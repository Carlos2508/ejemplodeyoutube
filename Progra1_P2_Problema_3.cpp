
#include <iostream>
#include <fstream>


using namespace std;
struct Ventas{
	int codigo;
	int tipo;
	int unidades;
	int semana;
}inventario, *Venta = &inventario;

void grabar_archivo();
void leer_archivo();
void mp();
void eliminar();
void modificar();

int main(){
	mp();
	
}

void mp(){
	int resp;
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal hola"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Cargar datos de ventas"<<"\n";
		cout<<" 2 - Verificar que pedidos pueden entregarse "<<"\n";
		cout<<" 3 - Modificar Registro"<<"\n";
		cout<<" 4 - Eliminar o anular Registro"<<"\n";
		cout<<" 5 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}
		else if (resp==3){		
			system("CLS");
			modificar();	
		}			
		else if (resp==4){
			system("CLS");
			eliminar();
		}
		else if (resp==5)
			break;
		else 
			break;
		
	} while(resp!=5);	
}

void grabar_archivo(){
	int n,x;
	ofstream db;
	int telar, botonesr, zziperr;
	int tela=500, botones=400, zziper=225;
	cout<<"Ingrese el numero de registros que ingresara: "<<endl;
	cin>>n;
	for(int i=0; i<n;i++){
	cout<<"Ingrese el codigo: "<<endl;
	cin>>Venta->codigo;
	cout<<"Ingrese el tipo: "<<endl;
	cin>>Venta->tipo;
	cout<<"Ingrese las unidades: "<<endl;
	cin>>Venta->unidades;
	if(Venta->tipo==1){
		tela-=Venta->unidades;
		botones-=Venta->unidades;
		botones-=Venta->unidades;
		if(tela<1){
			telar=tela;
			cout<<"Su pedido no se puede completar por que falta: "<<endl;
			cout<<"Se deben comprar "<<telar<<"Metros de tela por que ya no hay"<<endl;
			break;
		}
		if(botones<1){
			botonesr=botones;
			cout<<"Su pedido no se puede completar por que falta: "<<endl;
			cout<<"Se deben comprar "<<botonesr<<"botones por que ya no hay"<<endl;
			break;
		}
		
	}		
	if(Venta->tipo==2){
		tela-=Venta->unidades;
		tela-=Venta->unidades;
		zziper-=Venta->unidades;
		if(tela<=1){
			telar=(tela)*-1;
			cout<<"Su pedido no se puede completar por que falta: "<<endl;
			cout<<"Se deben comprar "<<telar<<"Metros de tela por que ya no hay"<<endl;
			break;
		}	
		if(zziper<=1){
			zziperr=(zziper)*-1;
			cout<<"Su pedido no se puede completar por que falta: "<<endl;
			cout<<"Se deben comprar "<<zziperr<<"zziperes por que ya no hay"<<endl;
			break;
		}
	}
	cout<<"Ingrese la semana 1,2,3,4: "<<endl;
	cin>>Venta->semana;
	try {
			db.open("inventario.txt",ios::app);
			db<<Venta->codigo<<"\t"<<Venta->tipo<<"\t"<<Venta->unidades<<"\t"<<Venta->semana<<endl;
			db.close();
			}
		catch(exception X){
			cout<<"Error en la manipulacion del archivo"<<endl;
			system("Pause");
		
		}				
	}

}

void leer_archivo(){
	int codigo=0;
	int tipop=0;	
	int unidadesven=0;
	int semanaentregar=0;
	ifstream db;	
	try{
		db.open("inventario.txt",ios::in);	
		cout<<"    Codigo|"<<"Tipo de producto|"<<"\t"<<" Unidades vendidas |"<<"\t"<<" Semana a entregar |"<<endl;		
		while (db>>codigo>>tipop>>unidadesven>>semanaentregar){
			cout<<"\t"<<codigo<<" | \t \t "<<tipop<<" |"<<"\t\t\t"<<unidadesven<<"  |"<<"\t\t\t"<<semanaentregar<<"  |"<<endl;					
			
		}	
		db.close();
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
	
	
}	

void modificar(){
	ifstream db_a; 
	ofstream db_n; 
	int aux,codigo,tipop,flag,unidadesven, semanaentregar, unidadesven1;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("inventario.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID al que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese Nota a modificar: "<<endl;
		cin>>unidadesven1;
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	

	while (db_a>>codigo>>tipop>>unidadesven>>semanaentregar){
		if(aux==codigo){
			db_n<<codigo<<"\t"<<tipop<<"\t"<<unidadesven1<<semanaentregar<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=codigo)
			db_n<<codigo<<"\t"<<tipop<<"\t"<<unidadesven<<semanaentregar<<endl;
						
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("inventario.txt");
		rename("Temporal.txt","inventario.txt");
	}	
	system("Pause");
}


void eliminar(){
	ifstream db_a; 
	ofstream db_n; 
	int aux,codigo,tipop,flag,unidadesven, semanaentregar;
	string onombre;
	remove("Temporal.txt");
	
	db_a.open("inventario.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>codigo>>tipop>>unidadesven>>semanaentregar){
		if(aux==codigo){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=codigo)
			db_n<<codigo<<"\t"<<tipop<<"\t"<<unidadesven<<"\t"<<semanaentregar<<endl;
					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("inventario.txt");
		rename("Temporal.txt","inventario.txt");
	}	
	system("Pause");
}
