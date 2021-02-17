
clase Perro extender Animal{
    cadena nombre$
    Persona propietario$
    Animal siguiente$
    publico void asignarInformacionPrimaria(cadena n1, entero ed, doble pes){
        nombre = n1$
        edad =ed$
        peso = pes$
    }
    void asignarPropietario(Persona p ){
        propietario = p$
    }
    
    sobrescribir publico entero getInformacionMascota(){
        cadena genero = ""$
        SI(propietario.genero == 'F'){
            genero = "FEMENINO"$
        }SINO{
            genero = "MASCULINO"$
        }
        imprimir( "==========================")$
        imprimir( "*       MASCOTA       *")$
        imprimir("==========================")$
        imprimir( "     nombre: "+nombre+"     ")$
        imprimir( "     edad: "+edad+"     ")$
        imprimir("     peso: "+peso+"     ")$
        imprimir( "==========================")$
        imprimir("*       PROPIETARIO       *")$
        imprimir("==========================")$
        imprimir("     nombre: "+propietario.nombre+" "+propietario.apellido+"     ")$
        imprimir( "     edad: "+propietario.edad+"     ")$
        imprimir( "     genero: "+genero+"     ")$
        imprimir("==========================")$
        retornar 1$
    }
}
