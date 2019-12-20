

/***
 *     ██████╗ ██████╗ ██████╗ ██╗████████╗    ████████╗██╗   ██╗██████╗ ███╗   ██╗███████╗██████╗
 *    ██╔═══██╗██╔══██╗██╔══██╗██║╚══██╔══╝    ╚══██╔══╝██║   ██║██╔══██╗████╗  ██║██╔════╝██╔══██╗
 *    ██║   ██║██████╔╝██████╔╝██║   ██║          ██║   ██║   ██║██████╔╝██╔██╗ ██║█████╗  ██████╔╝
 *    ██║   ██║██╔══██╗██╔══██╗██║   ██║          ██║   ██║   ██║██╔══██╗██║╚██╗██║██╔══╝  ██╔══██╗
 *    ╚██████╔╝██║  ██║██████╔╝██║   ██║          ██║   ╚██████╔╝██║  ██║██║ ╚████║███████╗██║  ██║
 *     ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝   ╚═╝          ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define EMPTY_STD fflush(stdin);
#define PAUSE system("pause");
//================>DEFINITION DES STRUCTURES<==============================
typedef struct MEMBER{
int id;
char civilite[50];
char nom[50];
char prenom[50];
char pseudo[50];
char deskPhoneIp[50];
char section[50];
char mail[250];
}MEMBER;
//========================>FIN DE DEFINITION DES STRUCTURES<==============================

	//------------------------------>[DEFINITION DES FONCTIONS ET DES VARIABLES GLOBALES]<-------------------------------
		void login();
		int MENU();
		void gotoxy(int,int);
		SYSTEMTIME t;
		void QUIT();
		void addDesk();
		void editDesk();
		void showDesk();
		void showCredits();
		int currentID;
                //DECLARATION DE VARIABLES STRING POUR L'AFFICHAGE CAR/CAR
        char dots[]=".....................OK!";
        char loading[]="\n>>>>>>>> CHECKING FOR DATABASE INTEGRITY ...\n>>>>>>>> CHECKING FOR \"assets/binaryIdData.orbit\"...\n>>>>>>>> CHECKING FOR \"databaseBinary.orbit\"...\n>>>>>>>> CHECKING FOR \"idBinaryCreator.orbit --INTEGRITY\"...";
        char confirmation[] = "\n OPERATION EFFECTUE AVEC SUCCES\n\n";
	//------------------------------[FIN DE DEFINITION FONCTIONS]------------------------------

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//===================================| M A I N |===================================
int main(int argc, char *argv[]) {
        int i, k, load=0;
        char tmp[5];
        EMPTY_STD
        //------------------------------[Declarations]------------------------------
            //CHECKING THE CURRENT ID FILE
        FILE *fCurrentId;
        fCurrentId = fopen("assets/binaryIdData.orbit", "rb");
        if(fCurrentId){
                fscanf(fCurrentId,"[%1s]",tmp);
        }else{
            printf("MISSING FILES \"binaryIdData.orbit\": ERROR 62");
        }
        fclose(fCurrentId);
        char car1;
        currentID = atoi(tmp);

            //CHECKING THE CURRENT ID FILE
        FILE *fDatabase;
        fDatabase = fopen("assets/databaseBinary.orbit", "rb");
        if(fDatabase){
            load = 1;
        }else{
            printf("MISSING FILES \"databaseBinary.orbit\": ERROR 73");
        }
        //------------------------------[FIN DECLARATION]------------------------------

        //        EXECUTION CONDITION
        if(load == 1){
                    system("color 4f");
                puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t==>{ !!METTEZ LA FENETRE EN PLEIN ECRAN PUIS APPUYEZ SUR ''ENTRER'' POUR LANCER LE PROGRAMME!! }<== ...");
                GetSystemTime(&t); //Recuperation DU Temps et de la Date ACtuelle de la Machine
                printf("\n\t\t\t\t\t\t\t==== On est Le %d-0%d-%d Et il est %dh:%dmn:%ds===\n ",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond);//Affichage DU Temps et de la Date ACtuelle de la Machine
                getchar();
                puts("\n\n");

                //confirm
                for (k = 0; k < strlen(loading); k++)
                {
                    putchar(loading[k]);//puts(" SUCCESS ");
                    Sleep(50);
                }
                puts("");
                for (k = 0; k < strlen(dots); k++){
                    putchar(dots[k]);//puts(" SUCCESS ");
                    Sleep(100);
                }
//                for(i=0;i<90;i++)
//                {
//                    printf("%c%c%c",219,219,219);
//                    Sleep(50);//Loading
//                }

                    printf ("\n\n\n\t\t\t\t==========<<<<<<<         CHARGEMENT TERMINE AVEC SUCC%cS ! APPUYER SUR ENTREE             >>>>>>========\n",144);


                getchar();//PAUSE
                system("cls");

                //APPEL DE LA FONCTION LOGIN
                connexion:
                login();
                system("color 0F");
                system("cls");
        }else{
            puts("\n\t\t ! ARRET DU PROGRAMME ! \n");
            PAUSE
            exit(0);
        }


        //        ======[ DEBUT DU PROGRAMME ]======


        while(1) //TOUJOURS AFFICHER LE MENU
        {
            switch(MENU())
            {
                case 1:
                    system("cls");
                    addDesk();
                    break;
                case 2:
                    EMPTY_STD
                   system("cls");
                   editDesk();
                   system("pause");
                    break;
                case 3:
                    system("cls");
                    showDesk();
                    getchar();
                    break;
                case 4:
                    system("cls");
                    showCredits();
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    login();
                    getchar();
                    break;
                case 0:
                    system("cls");
                    QUIT();
                    break;
            }
        }
}
//===================================| E N D  O F  M A I N |===================================


//--------------------------------->! [ FUNCTION 1 : M E N U ] !<---------------------------------
int MENU()
{
    int choix,i;
    do
    {
        system("cls");
            system("color f1");
                            puts("");
                            printf("\t\t\t\t   ECOBANK SENEGAL\t\t\t\t  %c%c%c  \t\t\t\t\tIT DIVISION\n",254,254,254);
                            for(i=1;i<=70;i++)
                            {
                                if(i==1) printf("\t\t\t\t\t\t%c",201);
                                if(i==70) printf("%c",187);
                                else
                                printf("%c",219);
                            }
						    printf("\n\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                        %c   MENU PRINCIPAL   %c                       %c\n",186,250,250,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c---------------------------------------------------------------------%c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c               |======>{ IT AGENT DESK HELPER }<======|              %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c---------------------------------------------------------------------%c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c       1 ----------------------->          AJOUTER UN AGENT          %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c       2 ---------------------->          MODIFIER UN AGENT          %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c       3 ----------------------->          LISTE DES AGENTS          %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c---------------------------------------------------------------------%c\n",186,186);
						    printf("\t\t\t\t\t\t%c       4 ---------------------->                    CREDITS          %c\n",186,186);
                            printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
                            printf("\t\t\t\t\t\t%c       5 ---------------------------->          DECONNEXION          %c\n",186,186);
                            printf("\t\t\t\t\t\t%c---------------------------------------------------------------------%c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                   !======>{ QUITTER : 0 }<======!                   %c\n",186,186);
						    printf("\t\t\t\t\t\t%c                                                                     %c\n",186,186);
						    printf("\t\t\t\t\t\t%c",200);
                            for(i=1;i<=69;i++)
						    {
                                printf("%c",205);
						    }
						    printf("%c\n\n",188);
	    puts("===>!{ FAITES VOTRE CHOIX }!<===");
        scanf("%d",&choix);
        if(choix<0 || choix>5)
        {
            puts("!!! CHOIX INDISPONIBLES !!!");
            system("pause");
        }
    }while(choix<0 || choix>5);
    return choix;
}
//--------------------------------->! [ END OF FUNCTION 1 ] !<---------------------------------



//--------------------------------->! [ FUNCTION 2 : ADD A MEMBER ] !<---------------------------------
void addDesk(){
    system("color 5f");
    printf("\t    |::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|\n\n");
    Sleep(150);
    printf("\t    |                                                        ->>> AJOUTER UN AGENT IT <<<-                                                         |\n\n");
    Sleep(150);
    printf("\t    |::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|\n\n");

    int n,i,k;
    MEMBER itmember;
    FILE *membersFile;
    membersFile = fopen("assets/databaseBinary.orbit", "ab");
    FILE *fCurrentId;
    fCurrentId = fopen("assets/binaryIdData.orbit", "w");

    if(membersFile){
        printf("\nENTRER LE NOMBRE D'AGENT A AJOUTER: ");
        scanf("\t%d",&n);
        if(fCurrentId){
            puts("");
            for(i=0;i<n;i++){
                printf("\n --> ENREGISTREMENT DE L'AGENT N%c: [ %d ] / [ %d ]", 248, i+1, n);
                EMPTY_STD
                itmember.id = currentID + 1;
                currentID = itmember.id ;
                fprintf(fCurrentId,"[%d]",currentID);
                puts("\n\tEntrer la CIVILITE de l'Agent (M. ou Mme):");
                gets(itmember.civilite);
                puts("\n\tEntrer le NOM de l'Agent (en Majuscule):");
                gets(itmember.nom);
                puts("\n\tEntrer le PRENOM de l'Agent:");
                gets(itmember.prenom);
                puts("\n\tEntrer le PSEUDO ou SURNOM de l'Agent:");
                gets(itmember.pseudo);
                puts("\n\tEntrer l' IP PHONE de l'Agent:");
                gets(itmember.deskPhoneIp);
                puts("\n\tEntrer le POSTE ou LA SECTION de l'Agent:");
                gets(itmember.section);
                puts("\n\tEntrer l'E-MAIL de l'Agent:");
                gets(itmember.mail);
                //Enregistrer l'agent saisie dans le fichier
                fwrite(&itmember,sizeof(itmember),1,membersFile);
                //confirm
                for (k = 0; k < strlen(confirmation); k++)
                {
                    putchar(confirmation[k]);//puts(" SUCCESS ");
                    Sleep(50);
                }
                puts("");
            }
            fclose(fCurrentId);
            fclose(membersFile);
        }else{
        puts("! ERROR 216 : CAN'T ACCESS THE DATABASE FILE !");
    }

    }else{
        puts("! ERROR 216 : CAN'T ACCESS THE DATABASE FILE !");
    }

}


//--------------------------------->! [ END OF FUNCTION 2 ] !<---------------------------------




//--------------------------------->! [ FUNCTION 3 : EDIT A MEMBER ] !<---------------------------------
void editDesk(){
    system("color 8e");
    printf("\t    |::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|\n\n");
    Sleep(150);
    printf("\t    |                                                        ->>> MODIFICATION INFOS AGENT <<<-                                                    |\n\n");
    Sleep(150);
    printf("\t    |::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|\n\n");

    int searchId, k;
    char change [100];
    MEMBER tmpAgent;
    FILE *membersFile;
    membersFile = fopen("assets/databaseBinary.orbit", "r+b");

    if(membersFile){
        puts("Entrer l'ID de l'Agent a modifier : ");
        scanf("%d", &searchId);
		EMPTY_STD
        while(fread(&tmpAgent, sizeof(tmpAgent), 1, membersFile) != 0){
            if(tmpAgent.id == searchId){
            	EMPTY_STD
                // CIVILITE
                printf("\nL'ANCIENNE CIVILITE ETAIT: {%s}\n\t==>ENTREZ LA NOUVELLE CIVILITE [0 Pour Annuler]: ", tmpAgent.civilite);
                gets(change);
                if(change[0]!='0'){
                    strcpy(tmpAgent.civilite, change);
                    printf("\n\t\t CIVILITE apres Changement:====>{%s}====\n",tmpAgent.civilite);
                }
                // NOM
                printf("\nL'ANCIEN NOM ETAIT: {%s}\n\t==>ENTREZ LE NOUVEAU NOM [0 Pour Annuler]: ", tmpAgent.nom);
                gets(change);
                if(change[0]!='0'){
                    strcpy(tmpAgent.nom, change);
                    printf("\n\t\t NOM apres Changement:====>{%s}====\n",tmpAgent.nom);
                }
                // PRENOM
                printf("\nL'ANCIEN PRENOM ETAIT: {%s}\n\t==>ENTREZ LE NOUVEAU PRENOM [0 Pour Annuler]: ", tmpAgent.prenom);
                gets(change);
                if(change[0]!='0'){
                    strcpy(tmpAgent.prenom, change);
                    printf("\n\t\t PRENOM apres Changement:====>{%s}====\n",tmpAgent.prenom);
                }
                //PSEUDO
                printf("\nL'ANCIEN PSEUDO ETAIT: {%s}\n\t==>ENTREZ LE NOUVEAU PSEUDO [0 Pour Annuler]: ", tmpAgent.pseudo);
                gets(change);
                if(change[0]!='0'){
                    strcpy(tmpAgent.pseudo, change);
                    printf("\n\t\t PSEUDO apres Changement:====>{%s}====\n",tmpAgent.pseudo);
                }
                //DESKPHONE-IP
                printf("\nL'ANCIEN DESKPHONE-IP ETAIT: {%s}\n\t==>ENTREZ LE NOUVEAU DESKPHONE-IP [0 Pour Annuler]: ", tmpAgent.deskPhoneIp);
                gets(change);
                if(change[0]!='0'){
                    strcpy(tmpAgent.deskPhoneIp, change);
                    printf("\n\t\t DESKPHONE-IP apres Changement:====>{%s}====\n",tmpAgent.deskPhoneIp);
                }
                //SECTION ou POSTE
                printf("\nL'ANCIEN POSTE ETAIT: {%s}\n\t==>ENTREZ LE NOUVEAU POSTE [0 Pour Annuler]: ", tmpAgent.section);
                gets(change);
                if(change[0]!='0'){
                    strcpy(tmpAgent.section, change);
                    printf("\n\t\t POSTE apres Changement:====>{%s}====\n",tmpAgent.section);
                }
                //EMAIL
                printf("\nL'ANCIENNE MAIL ETAIT: {%s}\n\t==>ENTREZ LA NOUVELLE ADRESSE MAIL [0 Pour Annuler]: ", tmpAgent.mail);
                gets(change);
                if(change[0]!='0'){
                    strcpy(tmpAgent.mail, change);
                    printf("\n\t\t MAIL apres Changement:====>{%s}====\n",tmpAgent.mail);
                }
                EMPTY_STD
                // REPLACEMENT
                fseek(membersFile, (long)-1*sizeof(tmpAgent), SEEK_CUR);
                fwrite(&tmpAgent, sizeof(tmpAgent), 1, membersFile);
                //confirm
                for (k = 0; k < strlen(confirmation); k++)
                {
                    putchar(confirmation[k]);//puts(" SUCCESS ");
                    Sleep(50);
                }
                puts("");
                EMPTY_STD
            }else{
                printf("AUCUN AGENT AVEC L'ID [ %d ] TROUVE", searchId);
            }
        }
        fclose(membersFile);
    }else{
        puts("! ERROR 303 : CAN'T ACCESS THE DATABASE FILE !");
    }
}

//--------------------------------->! [ END OF FUNCTION 3 ] !<---------------------------------




//--------------------------------->! [ FUNCTION 4 : LIST OF MEMBERS ] !<---------------------------------
void showDesk(){
    system("color 8e");
    gotoxy(15, 1);
    printf("|::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|\n\n");
    Sleep(150);
    gotoxy(15, 3);
    printf("|                                                         ->>> LISTES DES AGENTS IT <<<-                                                       |\n\n");
    gotoxy(15, 5);
    printf("|::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::|\n\n");

    int k=12;
    MEMBER tmpAgent;
    FILE *membersFile;
    membersFile = fopen("assets/databaseBinary.orbit", "rb");

    if(membersFile){
        gotoxy(19, 9);
        printf("%c===========================================================================================================================================%c", 201, 187);

        gotoxy(19, 10);
        printf("%c %5s || %5s || %10s || %18s || %10s || %5s || %25s || %20s %c\n", 219, "ID", "CIVILITE", "NOM", "PRENOM", "PSEUDO", "DESK-PHONE-IP", "SECTION ou POSTE", "E-MAIL",219);

        gotoxy(19, 11);
        printf("%c===========================================================================================================================================%c", 219, 219);

         while (fread(&tmpAgent, sizeof(tmpAgent), 1, membersFile) != 0){
            gotoxy(19,k);
            printf("%c %5d || %8s || %10s || %18s || %10s || %13s || %25s || %20s %c\n", 219, tmpAgent.id, tmpAgent.civilite, tmpAgent.nom, tmpAgent.prenom, tmpAgent.pseudo, tmpAgent.deskPhoneIp, tmpAgent.section, tmpAgent.mail,219);
            Sleep(150);
            k++;
            gotoxy(19, k);
            printf("%c-------------------------------------------------------------------------------------------------------------------------------------------%c", 219, 219);
            k++;
         }
        fclose(membersFile);
    }else{
        puts("! ERROR 216 : CAN'T ACCESS THE DATABASE FILE !");
    }
    getchar();
}
//--------------------------------->! [ END OF FUNCTION 4 ] !<---------------------------------




//--------------------------------->! [ FUNCTION 5 : SHOW-CREDITS ] !<---------------------------------
void showCredits(){
    puts("\n");
    printf ("\t\t===================================<<<<<<<<<< DEVELOPER INFOS >>>>>>>>>>>============================\n\n");
    printf ("\t\t                                                                                                       \n");
    printf ("\t\t    PSEUDO  : ==========<<<<<<<         Orbit Turner                              >>>>>>========       \n");
    printf ("\t\t    NOM     : ==========<<<<<<<         GUEYE                                     >>>>>>========       \n");
    printf ("\t\t    PRENOM  : ==========<<<<<<<         Mohamed                                   >>>>>>========       \n");
    printf ("\t\t    E-MAIL  : ==========<<<<<<<         orbitturner@orbitturner.yj.fr             >>>>>>========       \n");
    printf ("\t\t    WEBSITE : ==========<<<<<<<         http://orbitturner.yj.fr/                 >>>>>>========       \n");
    printf ("\t\t=====================================================================================================\n\n");
    printf ("\t\t    FACEBOOK: ==========<<<<<<<         www.facebook.com/orbitturner              >>>>>>========       \n");
    printf ("\t\t    TWITTER : ==========<<<<<<<         www.twitter.com/orbitlawtech              >>>>>>========       \n");
    printf ("\t\t    INSTA   : ==========<<<<<<<         www.instagram.com/orbitturner             >>>>>>========       \n");
    printf ("\t\t=====================================================================================================\n\n");
    printf ("\t\t    PROJECT : ==========<<<<<<<         IT DESK HELPER                            >>>>>>========       \n");
    printf ("\t\t=====================================================================================================\n\n");
    printf ("\t\t    PROMOTION : ==========<<<<<<<       STAGIAIRE - SEPT. 2019                    >>>>>>========       \n");
    printf ("\t\t===================================<<<<<<<<<< DEVELOPER INFOS >>>>>>>>>>>============================\n\n");
    puts("\n\n");

}
//--------------------------------->! [ END OF FUNCTION 4 ] !<---------------------------------



//========================>FONCTION LOGIN POUR GERER LA CONNEXION OU L'ACCES AU PROGRAMME<==============================
	void login()
	{
	    system("color 6");
		int a=0,i=0;
	    char uname[15],c=' ';//VAR POUR LA RECUPERATION DU UNAME SAISIE DU NOM D'UTILISATEUR
	    char pword[10],code[10];//CHAR PWORD ET CODE POUR LE CONTROLE ET LA RECUPERATION DU MDP
	    char user[15]="ithelpdesk"; //DEFINITION DU NOM D'UTILISATEUR ET DU MDP
	    char pass[10]="ecopass";
	    do
	    {
	        printf("\n\t\t\t\t   ECOBANK SENEGAL\t\t\t\t  %c%c%c  \t\t\t\t\tIT DIVISION\n",254,254,254);
	        printf("\t\t\t\t%c=======================================================================================================%c\n",201,187);
	        GetSystemTime(&t); //Recuperation DU Temps et de la Date ACtuelle de la Machine
			printf("\n\t\t\t\t\t\t\t==== Date: %d-0%d-%d \t Heure Actuelle: %dh:%dmn:%ds===\n ",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond);//Affichage DU Temps et de la Date ACtuelle de la Machine
	        printf("\n\n\t\t\t\t\t %c**************************{  FORMULAIRE DE CONNEXION  }**************************%c\n",219,219);
	        printf(" \n\t\t\t\t\tSAISISSEZ VOTRE NOM D'UTILISATEUR: [ ");
	        scanf("%s",&uname);
	        printf(" \n\t\t\t\t\tENTRER LE MOT DE PASSE: [ ");

	        while(i<10)
	        {
	            //MASQUAGE DU MDP
	            pword[i]=getch();//PRENDRE CAR PAR CAR DANS LE TABCHAR PWORD
	            c=pword[i]; //C POUR LE DU CAR ACTUELLE SAISIE
	            if(c==13) break;//SI LA SAISIE EST EGALE AU CODE ASCII 13 : ARRETER LA SAISIE
	            else printf("*");
	            i++;
	        }
	        pword[i]='\0';//CAR VIDE
	        //char code=pword;
	        i=0;
	        //scanf("%s",&pword);
	            if(strcmp(uname,"ithelpdesk")==0 && strcmp(pword,"ecopass")==0)
	        {
	        system("color a");
	        printf("\n\n\n\t\t\t\t\t\t\tCONNEXION REUSSIE !!!! BIENVENUE DANS NOTRE SYSTEME\n\n");
	        system("pause");
	        break;
	        }
	        else
	        {
	            system("color 4");
	            printf("\n\n\t\t\t\t\t\t\tIDENTIFIANT INCORRECT !!!! CONNEXION NON-REUSSI\n\n");
	            a++;

	            system("pause");//Pause
	            system("cls");
	            system("color 6");

	        }
	    }while(a<=2);

		if (a>2)//SI ON A SAISIE PLUS DE TROIS FOIS
		{
		    system("color 4f");
			puts("\n\n\t\t\t\t\t==>{ DESOLE, VOUS AVEZ ENTRE UN MAUVAIS NOM D'UTILISATEUR ET/OU MOT DE PASSE QUATRE ''3'' FOIS }<==\n");
	        puts("\n\t\t\t\t\t\t\t!!!==>{ ARRET DU PROGRAMME POUR RAISON DE SECURITE }<==!!! \n");
			system("pause");

	       	exit(0);
	    }
			system("cls");

	}
//========================>FIN DE FONCTION<==============================


//========================> FONCTION DE RECUPERATION DES REPERES <==============================
	COORD coord = {0, 0};
	// INitialisation des Coordonn²s sur 0,0
	//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
	COORD max_res,cursor_size;
	void gotoxy (int x,int y)
	{
		coord.X = x; coord.Y = y;
		//Coordonn²s X et Y

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//Place le curseur sur la place de l'ecran Specifier par le X et le Y
	}
//========================>FIN DE FONCTION<==============================



//========================>FONCTION DU MESSAGE DE THANK YOU LORS DE L'ARRET DU PROGRAMME<==============================
void QUIT(){
            char exit0;
            system("cls");
            system("color 4f");
            do{
            printf("\n\n\t\t\t\t\t==>{ Voulez-vous vraiment Quitter: y=(oui) ou n=(non)? }<==");
            scanf("%s",&exit0);
            }while(exit0!='y' && exit0!='n');
				if(exit0=='y')
                {
                    system("cls");
						system("color 0F");
						gotoxy(1,25);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						gotoxy(1,26);
						printf("   \xDB");
						gotoxy(1,27);
						printf("   \xDB");
						gotoxy(1,28);
						printf("   \xDB");
						gotoxy(1,29);
						printf("   \xDB");
						gotoxy(1,30);
						printf("   \xDB");
						gotoxy(1,31);
						printf("   \xDB");
						gotoxy(10,25);
						printf("\xDB     \xDB");
						gotoxy(10,26);
						printf("\xDB     \xDB");
						gotoxy(10,27);
						printf("\xDB     \xDB");
						gotoxy(10,28);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						gotoxy(10,29);
						printf("\xDB     \xDB");
						gotoxy(10,30);
						printf("\xDB     \xDB");
						gotoxy(10,31);
						printf("\xDB     \xDB");
						gotoxy(19,25);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						gotoxy(19,26);
						printf("\xDB     \xDB");
						gotoxy(19,27);
						printf("\xDB     \xDB");
						gotoxy(19,28);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						gotoxy(19,29);
						printf("\xDB     \xDB");
						gotoxy(19,30);
						printf("\xDB     \xDB");
						gotoxy(19,31);
						printf("\xDB     \xDB");
						gotoxy(28,25);
						printf("      \xDB");
						gotoxy(28,26);
						printf("\xDB\xDB    \xDB");
						gotoxy(28,27);
						printf("\xDB \xDB   \xDB");
						gotoxy(28,28);
						printf("\xDB  \xDB  \xDB");
						gotoxy(28,29);
						printf("\xDB   \xDB \xDB");
						gotoxy(28,30);
						printf("\xDB    \xDB\xDB");
						gotoxy(28,31);
						printf("\xDB");
					    gotoxy(37,25);
						printf("\xDB     \xDB");
						gotoxy(37,26);
						printf("\xDB    \xDB");
						gotoxy(37,27);
						printf("\xDB   \xDB");
						gotoxy(37,28);
						printf("\xDB\xDB\xDB\xDB");
						gotoxy(37,29);
						printf("\xDB   \xDB");
						gotoxy(37,30);
						printf("\xDB    \xDB");
						gotoxy(37,31);
						printf("\xDB     \xDB");
						gotoxy(46,25);
						printf("\xDB     \xDB");
						gotoxy(46,26);
						printf(" \xDB   \xDB");
						gotoxy(46,27);
						printf("  \xDB \xDB");
						gotoxy(46,28);
						printf("   \xDB");
						gotoxy(46,29);
						printf("   \xDB");
						gotoxy(46,30);
						printf("   \xDB");
						gotoxy(46,31);
						printf("   \xDB");
						gotoxy(55,25);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						gotoxy(55,26);
						printf("\xDB     \xDB");
						gotoxy(55,27);
						printf("\xDB     \xDB");
						gotoxy(55,28);
						printf("\xDB     \xDB");
						gotoxy(55,29);
						printf("\xDB     \xDB");
						gotoxy(55,30);
						printf("\xDB     \xDB");
						gotoxy(55,31);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						gotoxy(64,25);
						printf("\xDB     \xDB");
						gotoxy(64,26);
						printf("\xDB     \xDB");
						gotoxy(64,27);
						printf("\xDB     \xDB");
						gotoxy(64,28);
						printf("\xDB     \xDB");
						gotoxy(64,29);
						printf("\xDB     \xDB");
						gotoxy(64,30);
						printf("\xDB     \xDB");
						gotoxy(64,31);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			            Sleep(2000);
						exit(0);
                }
                if(exit0=='n'){
                    system("cls");
                }
}
//========================>FIN DE FONCTION<==============================
