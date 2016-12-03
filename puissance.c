void methodepuissance( matrice *A, int n){
	int i;
	matrice*X1 = NULL;
	matrice*X2 = NULL;
    creerMatrice(X1,n,1);
    creerMatrice(X2,n,1);
    fillMatrice(X1,1);
    do {
        copierMatrice(X2,X1);
        produitMatrice(&A,X1,X2);
    } while(not(compare(X1,X2)));


  }
}

int compare(matrice*A,matrice*B){
    int i, j;
    if((A->hauteur == B->hauteur) && (A->largeur == B->largeur))
    {
        for(i=0, i<hauteur, i++)
        {
            for(j=0,j<largeur,j++)
            {
                if(((*A)[i][j]-(*B)[i][j])>Epsilon)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
        return 0;
}
