cd ../tomartin
make
rm -f tomartin.a
make tomartin.a

cd ../vicmarti
make
rm -f vicmarti.a
ar -crs vicmarti.a $(find obj/db -name "*.o")

cd ../parser
make
rm -f parser.a
make parser.a

cd ../lexer
make
rm -f lexer.a
make lexer.a

cd ../command_executor
make

cd ../main_loop
c++ main_loop.cpp ../vicmarti/vicmarti.a ../tomartin/tomartin.a ../command_executor/code/build/**/*.o ../parser/parser.a ../lexer/lexer.a ../input_stream_orquestator/CommandActionAssociator.cpp -I ../vicmarti/src -g3
