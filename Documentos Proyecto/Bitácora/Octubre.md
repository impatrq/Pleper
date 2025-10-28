# 🗓️ Bitácora - Octubre 2025

## 📅 1️⃣ Semana (Lunes 29 - Viernes 3)


-  Santiago Tejeda: esta semana me dediqué a corroborar por qué los pulsos de la baldosa no llegaban a cargar el banco de capacitores, dentro de todas las razones una de las que me cuestioné era la falta de un capacitor de filtrado en la salida de la placa reciticadora, conectada en parallo, siendo esta conectada en paralelo, pero luego al probarlo en la baldosa dejó de dar tensión a la salida. Lo que terminó en tener que desoldarlo y optar por otra solución.
-  Mauricio Blasco: Diseñe las publicaciones de Instagram de la palca rectificadora y el banco de capacitores, además de diseñar la portada triple de la publicación en Canva. También diseñe el modelo 3d de los topes en Autocad y los pase al formato para imprimirlos en el CURA. Soldé los componentes que adquirimos en la placa rectificadora anteriormente hecha
---

## 📅 2️⃣ Semana (Lunes 6 - Viernes 10)


-  Santiago Tejeda: esta semana me dediqué a buscar el motivo por el cuál el banco de capacitores no cargaba. Llegué a la conclusión de que la constante de tiempo del capacitor de almacenamiento principal (10,000µF) excede en dos órdenes de magnitud la duración del pulso piezoeléctrico (20ms), resultando en una eficiencia de captura menor al 5%. Para resolver esto, se implementó un sistema de dos etapas capacitivas con un capacitor de acoplamiento (470µF) que presenta una constante de tiempo compatible con la duración del pulso. Denominandola "circuito de bombeo de carga capacitiva".
-  Mauricio Blasco: Esta semana complete el borde de caucho que cubre los costados de la baldosa, además de hacer un corte para que pasen los cables e intentar pegar con cemento de contacto la alfombra antideslizante a la baldosa, lo cual fracasamos ya que estaba ya seco el cemento de contacto, por lo que la despegamos.
---

## 📅 3️⃣ Semana (Lunes 13 - Viernes 17)


-  Santiago Tejeda: esta semana me dediqué a desoldar los pines macho-macho de la Raspberry Pico W, que estaban soldados al revés, aprovechando que teníamos las prácticas profesionlizantes en Newton SRL, nos brindaron uso de su equipo de microscopios y capacitación para soldar/desoldar estaño de la forma correcta, que me facilitó la operación. Luego empecé a investigar sobre los componentes para el prototipado del nuevo circuito de retroalimentación de bombeo de carga capacitiva.
-  Mauricio Blasco: Esta semana me encargue de medir la tensión tanto en la salida del circuito como en la salida de los grupos de piezoeléctricos, midiendo con uno, dos, tres y cuatro topes en un grupo y con un tope en cada esquina.
-  Ignacio Garcia: Esta semana empece con el codigo del proyecto. El mismo se encargaria de mostrar el porcentaje de carga del capacitor en un display LCD (con i2c incluido) y, ademas, mediante el uso de una pgina web las personas podrian ver en sus dispositivos como se carga en tiempo real el capacitor. La idea de esta semana es probar la parte del codigo para el display con el lenguaje de programacion Python.
---

## 📅 4️⃣ Semana (Lunes 20 - Viernes 24)

 
-  Santiago Tejeda: esta semana me dedique a investigar sobre el armado del circuito de retroalimentación para solucionar el problema de que los pulsos de la baldosa no logran ser captados por el banco de capacitores, ya que al tener una alta capacitancia y el tener un pulso de tan corto tiempo (20ms) los capacitores no logran captarlo. La solución que encontré fue una implementación de un circuito de bombeo de carga capacitiva que utiliza un capacitor pre-cargado como colchón de voltaje para maximizar la eficiencia en la captura de pulos piezoeléctricos. Logré armar el prototipo del circuito que, lentamente, carga el capacitor de 470 uF el cual proporciona la base de voltaje que posteriormente se le van a sumar el de los pulsos y así cargar el capacitor de 10.000uF, el cual daría por finalizado la etapa de carga de la baldosa. 
-  Mauricio Blasco: Esta semana me encargue de medir el tiempo de los pulsos generado por los piezoeléctricos con el objetivo de saber si el problema de la carga de los capacitores podría ser por la corta duración de estos, lo cual terminamos confirmando. También me encargue de comprar algunos componentes que requeríamos para seguir avanzando, los cuales eran 2 resistencias de 4,7 Mohm y dos tiras de 40 pines. Tambien medí la corriente en la salida del circuito tanto sin topes como con uno, dos, tres y cuatro topes. Por ultimo actualize con algunas mejoras el banner del proyecto para luego enviarlo.
---

🧾 **Observaciones generales del mes:**  
-  
-  
