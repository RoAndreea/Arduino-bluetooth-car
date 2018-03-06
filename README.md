# Arduino-bluetooth-car
Final arduino project


Proiectul ales de mine este o masina controlata prin bluetooth, ce evita obstacolele intalnite in calea sa.

Ca si constructie: masina este formata dintr-un sasiu, 2 motoare Micro Motor GA12-N20 cu Reductor 1:50 și Ax de 10 mm, 2 roti, un mini breadboard, un senzor de proximitate HC-SR04 si un Modul Bluetooth Master Slave HC-05.

Principiul de functionare: Folosind aplicatia Bluetooth Serial Controller (aplicatie ce ofera posibilatea de a programa butoanele), de pe un telefon Android, trimit semnal catre modulul bluetooth aflat pe masina. Aceasta preia comenzile si executa unul dintre cazurile: Forward, Forward Left, Forward Right, Back, Back Right, Back Left sau Off ( atunci cand primeste o comanda necunoscuta). Masina are totodata un senzor de distanta, iar atunci cand intalneste un obiect masina da putin cu spatele si apoi isi continua drumul spre inainte dreapta. 

https://docs.google.com/spreadsheets/d/1_GYeWjBXVv_4aekasxN6_g4DxXadq2Kq5P1_7F1olAA/edit#gid=441143683
