/* Sa consideram fisierul FIS.DAT ce contine numere ca in ex.
 2 11  3
 3 5    7  9 4
    1   2
 5
 Sa se afiseze suma numerelor de pe fiecare linie. O solutie sigura este
 cea din varianta de mai jos
 OBS. Nu conteaza nr. se spatii dintre numere.
 */
 #include<iostream.h>
 #include<fstream.h>
 #include<string.h>
 #include<strstrea.h>
 char linie[255],*sep=" ",*p;
 int s,nr;
 fstream f("c:\\scoala\\fis.dat",ios::in);
 void prel()
 {while(!f.eof()) {
    f.getline(linie,255);
    istrstream sir(linie,255);
    s=0;
    while(sir>>nr)s+=nr;
     cout<<s<<endl;
    }
 f.close();
 }
 void main()
 {prel();
 }