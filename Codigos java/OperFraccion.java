class Fraccion
{
	int numerador;
	int denominador;
	Fraccion(){}
	    Fraccion(int a,int b){
		this.numerador=a;
		this.denominador=b;
	}
	Fraccion SumaFraccion(Fraccion nueva)
	{
	Fraccion aux=new Fraccion();
	aux.denominador=denominador*nueva.denominador;
	aux.numerador=((aux.denominador/denominador)*numerador)+((aux.denominador/nueva.denominador)*nueva.numerador);
	return aux;
	}
	Fraccion RestaFraccion(Fraccion nuevaFraccion)
	{
	Fraccion aux2=new Fraccion();
	aux2.denominador=denominador*nuevaFraccion.denominador;
	aux2.numerador=((aux2.denominador/denominador)*numerador)-((aux2.denominador/nuevaFraccion.denominador)*nuevaFraccion.numerador);
	return aux2;	
	}
	Fraccion Multiplicacion(Fraccion nuevas){
		Fraccion aux3=new Fraccion();
		aux3.denominador=denominador*nuevas.denominador;
		aux3.numerador=numerador*nuevas.numerador;
		return  aux3;
	}
	Fraccion Division(Fraccion nuevaDivision)
	{
		Fraccion aux4=new Fraccion();
		aux4.denominador=denominador*nuevaDivision.numerador;
		aux4.numerador=numerador*nuevaDivision.denominador;
		return aux4;
	}
	void MuestraFraccion()
	{
		System.out.println("La Fraccion es :   "+numerador+"/"+denominador);
	}
}
public class OperFraccion {
    public static void main(String[] args) {
    Fraccion nuevasa=new Fraccion(5,2);
    Fraccion dos=new Fraccion(3,4);
    Fraccion Resp=new Fraccion();
    Resp=nuevasa.Division(dos);
    Resp.MuestraFraccion();
    }
}
