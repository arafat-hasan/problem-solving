/**************************************************************************************
*   FILE NAME: Where's Waldorf?-10010.c
*
*   PURPOSE:    Solve of Uva problem p10010
*
*   AUTHOR: Md.Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*	04 July 2016    New             0.0		In-completed
*	10 July 2016    Completed       1.0		Finished, checked, not submitted
* 	26 Sep 2016		Presentation,	1.0		Accepted
* 					'\n' changed
****************************************************************************************/

#include<stdio.h>
#include<ctype.h>

void wrd(char* a,char* b);
void checker(int line,int col,int pr);
void parallel(char *l,char *w);
void vertical(char* l,char* w);
void angle_u(char* l,char* w);
void angle_d(char* l,char* w);
int m,n,k;


int main() {
    int t,i,j,bb=0;
    char *a,*b;
    
    
    scanf("%d",&t);
    
    while(bb<t) {
		if(bb)
            printf("\n");
            
        scanf("%d %d",&m,&n);
        char l[m][n];
        
        for(i=0; i<m; i++) {
            scanf(" %[^\n]",&l[i][0]);
        }
        
        scanf("%d",&k);
        char w[k][50];
        
        for(i=0; i<k; i++) {
            scanf(" %[^\n]",&w[i][0]);
        }
        
        
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                l[i][j]=tolower(l[i][j]);
                
                
        for(i=0; i<k; i++)
            for(j=0; w[i][j]!=0; j++)
                w[i][j]=tolower(w[i][j]);
                
                
        a=&l[0][0];
        for(i=0; i<k; i++) {
            b=&w[i][0];
            wrd(a,b);
        }
        
        bb++;
    }
    
    return 0;
}
//main end



void wrd(char* a,char* b) {
    parallel(a,b);
    vertical(a,b);
    angle_d(a,b);
    angle_u(a,b);
    checker(0,0,1);
}



void checker(int line,int col,int pr) {
	
    static int line_r,col_r,i=0;
    
    
    if(pr==0) {
		
        if(i==0) {
            line_r=line;
            col_r=col;
        }
        
        i++;
        
        if(line<line_r) {
            line_r=line;
            col_r=col;
        } else if(line==line_r)
            if(col<col_r)
                col_r=col;
    } else {
        printf("%d %d\n",line_r+1,col_r+1);
        i=0;
    }
}

//parallel



void parallel(char *l,char *w) {
    int col,line,e=0,i,direction,col_r=n;
    for(line=0; line<m; line++) {//line
		
        direction=1;
        
        for(col=0; ; ) {//col
            if(*(l+n*line+col)==*w)
                for(i=0;; i++) {//i
					
                    if(*(w+i+1)==0) {
                        e=2;
                        break;
                    }
                    
                    
                    if(direction==1) {
                        if(*(l+n*line+col+i+1)!=*(w+i+1))
                            break;
                    } else {
                        if(*(l+n*line+col-i-1)!=*(w+i+1))
                            break;
                    }
                    
                }//i
                
                
            if(e==2) {
                if(col_r>col)
                    col_r=col;
                e=1;
            }
            
            
            if(col==n-1&&direction==1) {
                col=n;
                direction=-1;
            }
            
            
            if(direction==1)
				col++;
				
            else
				col--;
				
				
            if(col==-1)
				break;
				
        }//col
        
        
        if(e==1)
			break;
			
    }//line
    
    
    if(e>0)
        checker(line,col_r,0);
        
        
}




//vertical
void vertical(char* l,char* w) {
    int col,line,e=0,i,direction;
    for(col=0; col<n; col++) {//line
        direction=1;
        for(line=0; ; ) {//col
            if(*(l+n*line+col)==*w)
                for(i=1;; i++) {//i
                    if(*(w+i)==0) {
                        e=1;
                        break;
                    }
                    if(direction==1) {
                        if(*(l+n*(line+i)+col)!=*(w+i))
                            break;
                    } else {
                        if(*(l+n*(line-i)+col)!=*(w+i))
                            break;
                    }
                }//i
            if(e==1) {
                checker(line,col,0);
                e=0;
            }

            if(line==m-1&&direction==1) {
                line=n;
                direction=-1;
            }
            if(direction==1) line++;
            else line--;
            if(line==-1) break;
        }//col
    }//line
}

// angle_u
void angle_u(char* l,char* w) {
    int col,line,e=0,i,direction;
    for(line=0; line<m; line++) {//line
        direction=1;

        for(col=0; ; ) {//col

            if(*(l+line*n+col)==*w)
                for(i=1;; i++) {//i
                    if(*(w+i)==0) {
                        e=1;
                        break;
                    }

                    if(direction==1) {
                        if(col+i>=n) break;
                        if(*(l+n*(line+i)+col+i)!=*(w+i))
                            break;
                    } else {
                        if(col-i<0) break;
                        if(*(l+n*(line+i)+col-i)!=*(w+i))
                            break;
                    }

                }//i
            if(e==1) {
                checker(line,col,0);
                e=0;
            }

            if(col==n-1&&direction==1) {
                col=n;
                direction=-1;
            }
            if(direction==1) col++;
            else col--;

            if(col==-1) break;


        }//col
    }//line
}


//angle_d
void angle_d(char* l,char* w) {
    int col,line,e=0,i,direction;
    for(line=m-1; line>=0; line--) {//line
        direction=1;

        for(col=0; ; ) {//col

            if(*(l+line*n+col)==*w)
                for(i=1;; i++) {//i
                    if(*(w+i)==0) {
                        e=1;
                        break;
                    }

                    if(direction==1) {
                        if(col+i>=n) break;
                        if(*(l+n*(line-i)+col+i)!=*(w+i))
                            break;
                    } else {
                        if(col-i<0) break;
                        if(*(l+n*(line-i)+col-i)!=*(w+i))
                            break;
                    }

                }//i
            if(e==1) {
                checker(line,col,0);
                e=0;
            }

            if(col==n-1&&direction==1) {
                col=n;
                direction=-1;
            }
            if(direction==1) col++;
            else col--;

            if(col==-1) break;


        }//col
    }//line
}
