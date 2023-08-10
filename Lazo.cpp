#include <iostream>

int calcularCuadrante(int x,int y);
int calcularPuntaje(int contC0,int contC1,int contC2,int contC3,int contC4);

using namespace std;

int main()
{
    int cantTiros=2;//Cantidad de tiros del participante
    int numP=0,x=0,y=0,cuadrante=0,puntaje=0,contC0Total=0;
    int contC1=0,contC2=0,contC3=0,contC4=0,contC0=0,ganador,max=0;
    bool flag=false;
    do{
       
        cout<<"Ingrese el Numero del Participante:";
        cin>>numP;
        if(numP>=0){

            

            cout<<endl<<"Ingrese las coordenadas del";

            for(int i=0;i<cantTiros;i++){

                cout<<"tiro"<<i+1<<":"<<endl<<"X:";
                cin>>x;
                cout<<"Y:";
                cin>>y;
                cuadrante=calcularCuadrante(x,y);
                switch(cuadrante)
                {
                    case 0:
                        contC0++;
                        contC0Total++;
                        break;
                    case 1:
                        contC1++;
                        break;
                    case 2:
                        contC2++;
                        break;
                    case 3:
                        contC3++;
                        break;
                    case 4:
                        contC4++;
                        break;
                }
                
            }
            puntaje=calcularPuntaje(contC0,contC1,contC2,contC3,contC4);
        
            cout<<"PARTICIPANTE:"<<numP<<endl;
            cout<<"Tiros por cuadrante:\nC0:"<<contC0<<" C1:"<<contC1<<" C2:"<<contC2<<" C3:"<<contC3<<" C4:"<<contC4<<endl;
            cout<<"Puntaje:"<<puntaje<<endl;

            if(!flag || max<puntaje)
            {
                flag=true;
                max=puntaje;
                ganador=numP;
            }
            contC0=0;
            contC1=0;
            contC2=0;
            contC3=0;
            contC4=0;
        }
        
    }while(numP>=0);
    cout<<"GANADOR:"<<ganador<<" Puntaje:"<<max<<endl;
    cout<<"Tiros Totales al centro:"<<contC0Total;
   return 0;
}


int calcularCuadrante(int x,int y)//CALCULA EL CUADRANTE
{
    int cuadrante=0;

    if(x>0 && y>0 || x==0 && y>0 || y==0 && x>0)
        cuadrante=1;
    else if(x<0 && y>=0) //|| x<0 && y==0)
        cuadrante=2;
    else if(x<0 && y<0)
        cuadrante=3;
    else if(x>=0 && y<0)//|| x==0 && y<0)
        cuadrante=4;
    else if(x==0 && y==0)cuadrante=0;

    return cuadrante;
}

int calcularPuntaje(int contC0,int contC1,int contC2,int contC3,int contC4)//CALCULA LOS PUNTOS Y LOS SUMA
{
    int puntaje=0;

    puntaje=contC0*100+(contC1+contC2)*50+(contC3+contC4)*40;

    return puntaje;
}