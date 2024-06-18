Main: obj/Main.o obj/Fabrica.o obj/DTFecha.o obj/DTDireccion.o obj/DTUsuario.o obj/DTCliente.o obj/DTProducto.o obj/DTVendedor.o	obj/DTNotificacion.o obj/DTComentario.o obj/Producto.o obj/Vendedor.o	obj/Usuario.o	obj/Cliente.o				
	g++ obj/Main.o obj/Fabrica.o obj/DTFecha.o obj/DTDireccion.o obj/DTUsuario.o obj/DTCliente.o obj/DTProducto.o	obj/DTVendedor.o	obj/DTNotificacion.o obj/DTComentario.o	obj/Producto.o obj/Vendedor.o	obj/Usuario.o	obj/Cliente.o		-o Main

obj/Main.o: Main.cpp
	g++ -c Main.cpp -o obj/Main.o

obj/Fabrica.o: src/fabrica/Fabrica.cpp include/fabrica/Fabrica.hh
	g++ -c src/fabrica/Fabrica.cpp -o obj/Fabrica.o

obj/DTFecha.o: src/datatypes/DTFecha.cpp include/datatypes/DTFecha.hh
	g++ -c src/datatypes/DTFecha.cpp -o obj/DTFecha.o

obj/DTDireccion.o: src/datatypes/DTDireccion.cpp include/datatypes/DTDireccion.hh
	g++ -c src/datatypes/DTDireccion.cpp -o obj/DTDireccion.o	

obj/DTUsuario.o: src/datatypes/DTUsuario.cpp include/datatypes/DTUsuario.hh
	g++ -c src/datatypes/DTUsuario.cpp -o obj/DTUsuario.o	

obj/DTCliente.o: src/datatypes/DTCliente.cpp include/datatypes/DTCliente.hh
	g++ -c src/datatypes/DTCliente.cpp -o obj/DTCliente.o

obj/DTProducto.o: src/datatypes/DTProducto.cpp include/datatypes/DTProducto.hh
	g++ -c src/datatypes/DTProducto.cpp -o obj/DTProducto.o	

obj/DTVendedor.o: src/datatypes/DTVendedor.cpp include/datatypes/DTVendedor.hh
	g++ -c src/datatypes/DTVendedor.cpp -o obj/DTVendedor.o	

obj/DTNotificacion.o: src/datatypes/DTNotificacion.cpp include/datatypes/DTNotificacion.hh
	g++ -c src/datatypes/DTNotificacion.cpp -o obj/DTNotificacion.o	

obj/DTComentario.o: src/datatypes/DTComentario.cpp include/datatypes/DTComentario.hh
	g++ -c src/datatypes/DTComentario.cpp -o obj/DTComentario.o	

obj/Producto.o: src/Producto.cpp include/Producto.hh
	g++ -c src/Producto.cpp -o obj/Producto.o

obj/Vendedor.o: src/Vendedor.cpp include/Vendedor.hh
	g++ -c src/Vendedor.cpp -o obj/Vendedor.o	

obj/Usuario.o: src/Usuario.cpp include/Usuario.hh
	g++ -c src/Usuario.cpp -o obj/Usuario.o	

obj/Cliente.o: src/Cliente.cpp include/Cliente.hh
	g++ -c src/Cliente.cpp -o obj/Cliente.o	


clean:
	rm -f obj/*.o Main