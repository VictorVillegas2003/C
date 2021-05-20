/*I don't recommend to run it in the OnlineGDB because there the clear screen does not works (I don't know why).

 In order to compile it you only have to paste the code in whatever c application you have (Code:Blocks, Dev-C++, etc).

 In order to select the gender you want you have to enter the number that each one has, the same thing with the place
 For example, If you want to put the Country in studio, you would have to enter the number 7 (Country) and the number 1(Studio)
 and so on with the other ones.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(){

    int mG; /*This means musical gender*/
    int pL; /*This means place*/
    int c;
    bool  keep = true;

    while(keep)
    {
    	system("cls");
    	printf("\n\t\t\t\t\t\t\tMENU \n");
   		printf("\tYou have to select one of the following numbers in order to select the musical gender you want to play\n\n");
    	printf("\t1 .- Hard Rock \n");
    	printf("\t2 .- Pop\n");
    	printf("\t3 .- Rock\n");
    	printf("\t4 .- Indie\n");
    	printf("\t5 .- Blues\n");
    	printf("\t6 .- Metal\n");
    	printf("\t7 .- Country\n");

    	printf("\n\tYou have to select one of the following numbers in order to select the place where you want to play\n\n");
    	printf("\t1 .- Studio \n");
    	printf("\t2 .- Live presentation\n\n");

        printf("\nWhich musical gender would you like to play: ");
        scanf("%i", &mG);

        printf("Do you want to play in studio or in a live presentation: ");
        scanf("%i", &pL);

        if(mG <= 0 || mG >= 8 || pL <= 0 || pL >= 3)
		{
        	printf("\n\tInvalid input\n");
		}
        if(mG == 1 && pL == 1)
        {
            printf("\n-The guitar that you should use is a Gibson/Epiphone Less Paul studio (G Force tunning system) \n");
            printf("-This guitar fixes the problems with the tunning in the studio \n");
        }
        if(mG == 1 && pL == 2)
        {
            printf("\n-The guitar that you should use is a Gibson/Epiphone Less Paul standard 60's\n");
            printf("-This guitar has a power full sound, with which you will be able to sound as you want in the hard rock\n");
        }
        if(mG == 2 && pL == 1)
        {
            printf("\n-The guitar that you should use is a Fender/Squier Stratocaster with HSS pickups \n");
            printf("-It is recommended to use synths in order to modifie the sound as much as you want\n");
        }
        if(mG == 2 && pL == 2)
        {
            printf("\n-The guitar that you should use is a Fender American ultra luxe Stratocaster \n");
            printf("-During the performance you won't find any problems with the tunning thanks to the new locking tuning machines \n");
        }
        if(mG == 3 && pL == 1)
        {
            printf("\n-The guitar that you should use is a Fender Stratocaster with single coil pickups \n");
            printf("-This guitar is going to give you a clean and saturated sound\n");
        }
        if(mG == 3 && pL == 2)
        {
            printf("\n-The guitar that you should use is a Fender Noventa Stratocaster \n");
            printf("-Thanks to the two noventa single coils that this guitar has you will have a pretty versatile sound \n");
        }
        if(mG == 4 && pL == 1)
        {
            printf("\n-The guitar that you should use is the Rickenbacker 360 \n");
            printf("-This guitar is one of the more accessible guitars because of its price (600-800 dollars), its fine fingerboard allows to play soft chords\n");
        }
        if(mG == 4 && pL == 2)
        {
            printf("\n-The guitar that you should use is a Fender Noventa Jazzmaster \n");
            printf("-This guitar gives you a wide array of multifaceted and robust tones thanks to the dynamic range single-coil pickups\n");
        }
        if(mG == 5 && pL == 1)
        {
            printf("\n-The guitar that you should use is a Gibson ES-335 \n");
            printf("-The semi hollow body and the humbucker Gibson PAF pickups of this guitar gives you a warm sound \n");
        }
        if(mG == 5 && pL == 2)
        {
            printf("\n-The guitar that you should use is a Guild Starfire \n");
            printf("-The humbuckers of this guitar gives a sound with a high detail that can produce high levels of gain and a clean sound for the blues\n");
        }
        if(mG == 6 && pL == 1)
        {
            printf("\n-The guitar that you should use is a Ibanez RG \n");
            printf("-The large and plane fingerboard allows you to play expressive metallic solos besides the passive pickups offer a high distortion level \n");
        }
        if(mG == 6 && pL == 2)
        {
            printf("\n-The guitar that you should use is a Gibson Flying V or a Gibson Explorer \n");
            printf("-Besides Their awesom aspect, the double pickups and their caoba body give these guitars a thick and solid sound, ideal to play metal \n");
        }
        if(mG == 7 && pL == 1)
        {
            printf("\n-The guitar that you should use is a Epiphone EJ-200SCE\n");
            printf("-The palisander system of the bridge and the configuration eSonic2 of the pickups of this electroacustic guitar gives to the owner a beautiful and solid sound for country and related musical gender");
        }
        if(mG == 7 && pL == 2)
        {
            printf("\n-The guitar that you should use is a Fender Telecaster \n");
            printf("-With this guitar you can make a simple and sansitive sound, this is one of most versatile guitars allowing you to make a lot of combinations between the bridge pickup and the single-coil pickups \n");
        }
        printf("\nwould you like to continue?(YES .- 1, NO .- 2): ");
            scanf("%i", &c);
            if (c == 1)
            {
            	keep = 1;
			}
			else
			{
				keep = 0;
			}
    }
    return 0;
}
