# ConcurrencyExercise

## Cooperating/Competing Tasks:

**Comentario:** El código demuestra cooperación entre hilos para el acceso a la base de datos. Múltiples lectores y escritores están sincronizados mediante mutex y variables de condición, asegurando la integridad de los datos.

## Threads/Processes:

**Comentario:** El código utiliza hilos, permitiendo la ejecución concurrente dentro del mismo espacio de memoria. Los hilos son adecuados para este escenario, ya que comparten recursos de manera más eficiente en comparación con procesos separados.

## Uso de Sockets y Hilos Conjuntamente:

**Comentario:** El código no implica el uso directo de sockets. En cambio, se basa en hilos para la ejecución en paralelo. Los sockets suelen utilizarse para la comunicación entre procesos, lo cual no es el enfoque de esta implementación.

## Sockets vs. WebSockets:

**Comentario:** El código no utiliza sockets ni websockets de manera explícita. Los sockets son un mecanismo de comunicación de nivel más bajo, mientras que los websockets ofrecen un protocolo de nivel superior para la comunicación bidireccional en tiempo real, comúnmente utilizado en aplicaciones web.
