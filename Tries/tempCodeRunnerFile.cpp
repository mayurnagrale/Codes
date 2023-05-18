for(int i=0;i<B.size();i++){
        maxi = max(maxi,getMax(root,B[i]));
    }

    cout<<maxi;