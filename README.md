# prisionersVe
Program to solve the prisioners challenge on the video from Dr. Derek and his channel Veritasium.
Video Link: https://www.youtube.com/watch?v=ksasmB0YPzw

<h1>Enunciado del problema</h1>
Son 100 prisioneros con un numero del 1 al 100 cada uno
El numero de cada prisionero se coloca en una caja de forma aleatoria (100 cajas)

Se permite entrar a los prisioneros de a 1 en 1 y  puede revisar 50 cajas, las que desee, para encontrar su numero y al encontrarlo deja la habitacion.

Si los 100 prisionereos encuentran su propio numero durante su turno, seran liberados, de lo contrario ejecutados.

<h2>Estrategia propuesta en el video</h2>

Al entrar en la habitacion, el prisionero abre la caja que tiene su numero, si el numero que encuentra no es el de él, entonces va a abrir la caja con el numero que encontro y eso sigue hasta que encuentre el numero o hasta que pasen las 50 cajas.
