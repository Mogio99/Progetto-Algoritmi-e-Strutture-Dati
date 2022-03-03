***PRE-COMPILAZIONE***

1) creare una directory con nome "lib" e copiare all'interno i file
   -> junit-4.12.jar
   -> hamcrest-core-1.3.jar

***COMPILAZIONE***
1) compilare con ant all, verrano generate due directory "build" e "classes"

***CANCELLAZIONE *.o e *.exe***

1) ant clean


***ESECUZIONE***

--PER ESEGUIRE l'algoritmo di kruskal ---
1) entrare nella directory "classes"
2) eseguire da tastiera comando "java Main" , il programma verrà eseguito

--PER ESEGUIRE I TEST--
1) entrare nella directory "classes"
2) eseguire da testiera di comando java -cp '.;../lib/junit-4.12.jar;../lib/hamcrest-core-1.3.jar'  TestMain




