for (( i=50; i<=500; i=i+50 ))
do
	./main_para car.csv 0 0.001 $i x x cartemp;
	./main_para car.csv 0 0.001 $i x x cartemp;
	./main_para car.csv 0 0.001 $i x x cartemp;
	./main_para car.csv 0 0.001 $i x x cartemp;
	./main_para car.csv 0 0.001 $i x x cartemp;
	./main_para car.csv 0 0.001 $i s x cartemp;
	./main_para car.csv 0 0.001 $i s x cartemp;
	./main_para car.csv 0 0.001 $i s x cartemp;
	./main_para car.csv 0 0.001 $i s x cartemp;
	./main_para car.csv 0 0.001 $i s x cartemp;
	./main_para car.csv 0 0.001 $i p x cartemp;
	./main_para car.csv 0 0.001 $i p x cartemp;
	./main_para car.csv 0 0.001 $i p x cartemp;
	./main_para car.csv 0 0.001 $i p x cartemp;
	./main_para car.csv 0 0.001 $i p x cartemp;
	./main_para car.csv 0 0.001 $i n x cartemp;
	./main_para car.csv 0 0.001 $i n x cartemp;
	./main_para car.csv 0 0.001 $i n x cartemp;
	./main_para car.csv 0 0.001 $i n x cartemp;
	./main_para car.csv 0 0.001 $i n x cartemp;
	./main_para car.csv 0 0.001 $i e x cartemp;
	./main_para car.csv 0 0.001 $i e x cartemp;
	./main_para car.csv 0 0.001 $i e x cartemp;
	./main_para car.csv 0 0.001 $i e x cartemp;
	./main_para car.csv 0 0.001 $i e x cartemp;
done

