GitHub
https://github.com/CosteaCristian1/POO-Project-2

Acesta este un program care se ocupă cu gestionarea angajaților unei firme de IT.
Are un meniu pentru query-uri prin care poți adăuga un agajat, să afișezi datele
unui anumit angajat prin intermediul ID-ului, poți promova un angajat, poți genera
un raport al activității care arată totalul de membrii, membrii pe fiecare departament,
dar și salariul mediu, poți afișa detaliile tuturor angajaților, poți salva datele
curente într-un fișier txt și poți șterge un angajat.

Am împărțit codul în mai multe fișiere header. (meniu.h, tester.h, programator.h, manager.h, angajat.h, exceptii.h)
Nu s-a folosit namespace std

Am folosit clasa de bază Angajat din care au reieșit clasele manager, programator și tester.

Am folosit funcții virtuale pentru afișarea de detalii, generarea activității, calculul de salariu și promovare
Folosesc pointeri la clasa de bază pentru a crea clasele derivate și a le putea pune în vector.

Apelez constructorul din clasa de bază în constructorii claselor derivate.

Folosesc dynamic_cast în if-uri pentru a vedea dacă un obiect este de tip manager, programator sau tester.

Am creat 4 clase pentru exceptii în exceptii.h cu o clasă de bază ExceptieAngajat universală și 3 moștenitori
pentru ID incorect, date incomplete și funcție necunoscută.

Folosesc o funcție și un contor static pe care îl incrementez pentru fiecare membru adăugat.

