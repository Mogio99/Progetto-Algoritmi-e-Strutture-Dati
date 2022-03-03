***PRE-COMPILAZIONE***

1) creare una directory con nome "lib" e copiare all'interno i file
   -> junit-4.12.jar
   -> hamcrest-core-1.3.jar

***COMPILAZIONE***
1) compilare con ant all, verrano generate due directory "build" e "classes"

***CANCELLAZIONE *.o e *.exe***

1) ant clean


***ESECUZIONE***

1) Spostarsi sulla directory classes
2) Eseguire il test java  -cp "lib/junit-4.12.jar; lib/hamcrest-core-1.3.jar;." TestMain