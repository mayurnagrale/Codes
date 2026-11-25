"""Step 1, by hand: embeddings, cosine similarity and top-k with TINY vectors.

Real embeddings (nomic-embed-text) have 768 numbers each, which is too many
to look at. Here every "embedding" has only 4 numbers, and each number has a
name we chose ourselves, so you can check every calculation on paper.

    position 0 = how much is this about ANIMALS?
    position 1 = how much is this about VEHICLES?
    position 2 = how much is this about FOOD?
    position 3 = how much is this about PLACES / GEOGRAPHY?

(In a real model the positions have no names. The model invents its own
"directions of meaning" while it trains. The math is identical though.)

No libraries needed. Run:
    python rag-learning/step1/toy_retrieval.py
"""

import math

TOP_K = 3

# ---------------------------------------------------------------------------
# Our "textbook": 6 chunks, each with a hand-made embedding.
# In rag.py, the embedding model writes these numbers for you.
# ---------------------------------------------------------------------------
CHUNKS = [
    ("Cats are small furry pets that purr.",         [0.9, 0.0, 0.1, 0.0]),
    ("Kittens sleep up to 20 hours a day.",          [0.8, 0.0, 0.0, 0.1]),
    ("Dogs love to eat meat and bones.",             [0.7, 0.0, 0.5, 0.0]),
    ("A car needs fuel and sometimes new tyres.",    [0.0, 0.9, 0.1, 0.0]),
    ("Bicycles are vehicles with two wheels.",       [0.1, 0.8, 0.0, 0.0]),
    ("Bread is baked from flour, water and yeast.",  [0.0, 0.0, 0.9, 0.0]),
]

# Questions, also with hand-made embeddings. In rag.py, the SAME embedding
# model that embedded the chunks also embeds the question.
QUESTIONS = [
    ("How long do kittens sleep?",      [0.85, 0.0, 0.05, 0.0]),
    ("What does a car need?",           [0.0, 0.95, 0.05, 0.0]),
    ("What do dogs eat?",               [0.6, 0.0, 0.6, 0.0]),
    ("What is the capital of France?",  [0.0, 0.0, 0.0, 1.0]),
]


def dot(a, b):
    """Multiply matching positions, then add everything up."""
    return sum(x * y for x, y in zip(a, b))


def length(a):
    """How long the arrow is (Pythagoras: square, add, square root)."""
    return math.sqrt(sum(x * x for x in a))


def cosine(a, b):
    """Do the two arrows point the same way? 1 = same, 0 = unrelated."""
    return dot(a, b) / (length(a) * length(b))


def heading(title):
    print("\n" + "=" * 72)
    print(title)
    print("=" * 72)


# ---------------------------------------------------------------------------
heading("LESSON 1: cosine similarity, one calculation done slowly")
# ---------------------------------------------------------------------------
q_text, q = QUESTIONS[0]
c_text, c = CHUNKS[1]
print(f"question : {q_text!r:40} -> {q}")
print(f"chunk    : {c_text!r:40} -> {c}")
print()
print("step 1  dot product = multiply matching positions, then add:")
parts = " + ".join(f"{x}*{y}" for x, y in zip(q, c))
print(f"        {parts} = {dot(q, c):.4f}")
print("step 2  length of each arrow = sqrt(sum of squares):")
print(f"        |question| = {length(q):.4f}    |chunk| = {length(c):.4f}")
print("step 3  cosine = dot / (|question| * |chunk|):")
print(f"        {dot(q, c):.4f} / ({length(q):.4f} * {length(c):.4f}) = {cosine(q, c):.4f}")
print()
print("Why divide by the lengths? So only DIRECTION counts, not size.")
print("A long paragraph and a short question can still 'point the same way'.")

# ---------------------------------------------------------------------------
heading("LESSON 2: top-k retrieval, exactly what rag.py does")
# ---------------------------------------------------------------------------
for q_text, q in QUESTIONS:
    print(f"\nQuestion: {q_text}")
    scored = sorted(
        ((cosine(q, vec), text) for text, vec in CHUNKS),
        reverse=True,  # biggest score first
    )
    for rank, (score, text) in enumerate(scored, start=1):
        tag = "<-- top-k, sent to the LLM" if rank <= TOP_K else ""
        print(f"  {rank}. {score:.3f}  {text:45} {tag}")
    gap = scored[0][0] - scored[1][0]
    print(f"  gap between #1 and #2: {gap:.3f}")

print("""
Things to notice:
 * Kittens: WRONG #1! 'Cats ... purr' beat 'Kittens sleep ...' by 0.008.
   Our map only has 4 directions, and none of them is "sleep". So both
   chunks just look like "animal", and the retriever cannot tell them apart.
   This is why real models use hundreds of directions (768 for nomic):
   more directions = finer differences in meaning can be seen.
   Luckily the right chunk is still #2, so with k=3 the LLM still gets it.
   That is one reason we send k chunks instead of only 1.
 * Car: right #1, but the gap is tiny (0.007). Car and bicycle both look
   like "vehicle" only. A tiny gap means the retriever was NOT sure.
 * Dogs: right #1 with a big gap (0.206). The question points half toward
   animals and half toward food, and so does the dog chunk. Confident.
 * France: nothing is about France, yet 3 chunks are still sent to the LLM!
   Top-k ALWAYS returns k chunks. It never says "nothing found".
   (Real models give unrelated text around 0.4 instead of 0, which hides
   this even better. Low, bunched-together scores are the warning sign.)
""")

# ---------------------------------------------------------------------------
heading("LESSON 3: why not just match words? (a 'dumb' embedding)")
# ---------------------------------------------------------------------------
# A word-count embedding: one position per word in the vocabulary.
# It matches SPELLING, not MEANING.
def word_count_embed(text, vocab):
    words = [w.strip(".,?!").lower() for w in text.split()]
    return [words.count(v) for v in vocab]

pair = ("Do cats nap a lot?", "Kittens sleep up to 20 hours a day.")
vocab = sorted({w.strip(".,?!").lower() for s in pair for w in s.split()})
a, b = (word_count_embed(s, vocab) for s in pair)
print(f"{pair[0]!r} vs {pair[1]!r}")
print(f"word-count cosine = {cosine(a, b):.3f}")
print("""
The only shared word is 'a', so the score is tiny, even though both
sentences are about cats sleeping. 'cats' != 'kittens' and 'nap' != 'sleep'
when you only compare spelling.

A trained embedding model has read billions of sentences, so it learned that
kitten ~ cat and nap ~ sleep. That is why in your earlier Ollama run,
'I have a pet cat' vs 'My kitten loves to sleep' scored 0.635 even though
they share no important word.
""")

# ---------------------------------------------------------------------------
heading("LESSON 4: why question and chunks MUST use the same model")
# ---------------------------------------------------------------------------
# Pretend 'model B' uses a different order: [food, places, animals, vehicles].
# Same idea of the question, different meaning for each position.
def model_b(vec_a):
    animals, vehicles, food, places = vec_a
    return [food, places, animals, vehicles]

q_text, q = QUESTIONS[0]          # kittens question
q_from_b = model_b(q)             # embedded with the WRONG model
print(f"Question: {q_text}  (embedded with model B, chunks with model A)")
for score, text in sorted(((cosine(q_from_b, v), t) for t, v in CHUNKS), reverse=True):
    print(f"  {score:.3f}  {text}")
print("""
Now 'Bread is baked...' wins a question about kittens! Each model draws its
own map of meaning, so mixing them is like reading Paris coordinates on a map
of Tokyo. If you ever change the embedding model, re-embed ALL your chunks.
""")
