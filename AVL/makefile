all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/AgacDugum.cpp -o ./lib/AgacDugum.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Agac.cpp -o ./lib/Agac.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/AgacDugum.o ./lib/Dugum.o ./lib/Agac.o ./lib/BagliListe.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program