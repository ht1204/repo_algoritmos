
package Modelo;


public class CodigoModel {
    
    private int codigo;
    private int codigoDigitos[];

    public CodigoModel() {
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public int[] getCodigoDigitos() {
        return codigoDigitos;
    }

    public void setCodigoDigitos(int[] codigoDigitos) {
        this.codigoDigitos = codigoDigitos;
    }
    
    public void setDigitos(int index,int digito){
        this.codigoDigitos[index]=digito;
    }
 
}
