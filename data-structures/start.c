#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

main()

{

FILE *ftp, *ftp2;
int i, c1, store_atm_no[10000], store_res_no[10000];
char line[200], word[5], slno[6], atm_nm[4], store_atm_nm[10000][4], res_nm[4], store_res_nm[10000][4], res_no[5], ch_id[10000], x[9], y[9], z[9] ;
float store_x[10000], store_y[10000], store_z[10000], tot_x, tot_y, tot_z, cm_x, cm_y, cm_z;

ftp = fopen( "12AS.pdb" , "r" ); 
ftp2 = fopen("result.pdb" , "w");
c1 = 0;

while(fgets(line,200,ftp)!=NULL)
    {
        for(i=0;i<4;i++) word[i] = line[i];
        word[4] = '\0';
        
        if(strcmp( word, "ATOM" ) == 0)
            {
                for(i=0;i<5;i++) slno[i] = line[i+6];
                slno[5] = '\0';
                store_atm_no[c1] = atoi(slno);    
                        
                for(i=0;i<3;i++) atm_nm[i] = line[i+13];
                atm_nm[3] = '\0';
                strcpy(store_atm_nm[c1], atm_nm);

                for(i=0;i<3;i++) res_nm[i] = line[i+17];
                res_nm[3] = '\0';
                strcpy(store_res_nm[c1], res_nm);

                ch_id[c1] = line[21];

                for(i=0;i<4;i++) res_no[i] = line[i+22];
                res_no[4] = '\0';
                store_res_no[c1] = atoi(res_no);

                for(i=0;i<8;i++) x[i] = line[i+30];
                x[8] = '\0';
                store_x[c1] = atof(x);

                for(i=0;i<8;i++) y[i] = line[i+38];
                y[8] = '\0';
                store_y[c1] = atof(y);

                for(i=0;i<8;i++) z[i] = line[i+46];
                z[8] = '\0';
                store_z[c1] = atof(z);

                c1++;
            }
    }

    tot_x = tot_y = tot_z = 0.0;
    //printf("%d",c1);
        for(i=0;i<c1;i++)
            {
                tot_x = tot_x + store_x[i];
                tot_y = tot_y + store_y[i];
                tot_z = tot_z + store_z[i];
            }
    printf("%f\n",tot_x);
    cm_x = tot_x/c1;
    cm_y = tot_y/c1;
    cm_z = tot_z/c1;

        for(i=0;i<c1;i++)
            {
                fprintf( ftp2, "ATOM %5d %s %s %c%4d %8.3f%8.3f%8.3f\n",store_atm_no[i], store_atm_nm[i], store_res_nm[i], ch_id[i], store_res_no[i], store_x[i], store_y[i], store_z[i] );
            }

    printf("x=%f y= %f z= %f", cm_x, cm_y, cm_z);    
    fclose(ftp);
    fclose(ftp2);

    } 