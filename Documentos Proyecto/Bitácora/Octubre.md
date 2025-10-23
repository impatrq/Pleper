# 🗓️ Bitácora - Octubre 2025

## 📅 1️⃣ Semana (Lunes 29 - Viernes 3)


-  Santiago Tejeda: esta semana me dediqué a corroborar por qué los pulsos de la baldosa no llegaban a cargar el banco de capacitores, dentro de todas las razones una de las que me cuestioné era la falta de un capacitor de filtrado en la salida de la placa reciticadora, conectada en parallo, siendo esta conectada en paralelo, pero luego al probarlo en la baldosa dejó de dar tensión a la salida. Lo que terminó en tener que desoldarlo y optar por otra solución.

---

## 📅 2️⃣ Semana (Lunes 6 - Viernes 10)


-  Santiago Tejeda: esta semana me dediqué a buscar el motivo por el cuál el banco de capacitores no cargaba. Llegué a la conclusión de que la constante de tiempo del capacitor de almacenamiento principal (10,000µF) excede en dos órdenes de magnitud la duración del pulso piezoeléctrico (20ms), resultando en una eficiencia de captura menor al 5%. Para resolver esto, se implementó un sistema de dos etapas capacitivas con un capacitor de acoplamiento (470µF) que presenta una constante de tiempo compatible con la duración del pulso. Denominandola "circuito de bombeo de carga capacitiva".

---

## 📅 3️⃣ Semana (Lunes 13 - Viernes 17)


-  Santiago Tejeda: esta semana me dediqué a desoldar los pines macho-macho de la Raspberry Pico W, que estaban soldados al revés, aprovechando que teníamos las prácticas profesionlizantes en Newton SRL, nos brindaron uso de su equipo de microscopios y capacitación para soldar/desoldar estaño de la forma correcta, que me facilitó la operación. Luego empecé a investigar sobre los componentes para el prototipado del nuevo circuito de retroalimentación de bombeo de carga capacitiva.

---

## 📅 4️⃣ Semana (Lunes 20 - Viernes 24)

 
-  Santiago Tejeda: esta semana me dedique a investigar sobre el armado del circuito de retroalimentación para solucionar el problema de que los pulsos de la baldosa no logran ser captados por el banco de capacitores, ya que al tener una alta capacitancia y el tener un pulso de tan corto tiempo (20ms) los capacitores no logran captarlo. La solución que encontré fue una implementación de un circuito de bombeo de carga capacitiva que utiliza un capacitor pre-cargado como colchón de voltaje para maximizar la eficiencia en la captura de pulos piezoeléctricos.

---

🧾 **Observaciones generales del mes:**  
-  
-  
