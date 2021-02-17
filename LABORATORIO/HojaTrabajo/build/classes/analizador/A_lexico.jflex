
package analizador;
import java_cup.runtime.*;
import java.util.LinkedList;


%%
/*      area de declaracion  tokens   */
%{
    //----> area de declaraciones codigo java
    String cadena="";
    //----> funciones y variables necesarias
%}

/*   area de directivas  */
%8bit
%full
%unicode
%cupsym sym
%class AnalizadorLexico
%cup
%public
%line
%column
%char
%ignorecase

/*      area de ER      */

Comentario = "//" [^\r\n]* [^\r\n] 
ComentarioMulti = "<!" [^/] ~"!>" | "<!" "/"+ "!>" 

digito = [0-9]
entero =[0-9]+ |["-"][0-9]+
decimal =[0-9]+ "." [0-9]+ 
//cadena =[\"] [^\"\n]* [\"\n]
letra = [a-zA-ZñÑ]
id = {letra}+({letra}|{digito}|"_")* 
espacio = \t|\f|" "|\r|\n

%state STR
%state STR1


%%

/*------ 3ro. codigo de usuario --------*/
//acciones
/* espacios en blanco*/
{espacio}   {/*Ignorar*/} 

<STR>{
[\"] {  String temporal=cadena; cadena=""; yybegin(YYINITIAL);
        System.out.println("Reconocido: <<"+cadena+">>, cadena");
        return new Symbol(sym.str, yychar,yyline,temporal);   }
[\\] { cadena+=yytext(); yybegin(STR1);}
[^\"] { cadena+=yytext(); }
}

<STR1>{
.    { cadena+=yytext(); yybegin(STR);}
}

<YYINITIAL> "CONJ" {return new Symbol(sym.conj,yycolumn,yyline,yytext());}
<YYINITIAL> "Extraer" {return new Symbol(sym.tExtraer,yycolumn,yyline,yytext());}
<YYINITIAL> "->" {return new Symbol(sym.flecha,yycolumn,yyline,yytext());}
<YYINITIAL> "%%" {return new Symbol(sym.simSeparacion,yycolumn,yyline,yytext());}

<YYINITIAL> {letra}     {System.out.println("letra: "+yytext() );   return new Symbol(sym.letra,yycolumn,yyline,yytext());}
<YYINITIAL> {entero}    {System.out.println("entero: "+yytext() );  return new Symbol(sym.entero,yycolumn,yyline,yytext());}
<YYINITIAL> {decimal}   {System.out.println("decimal: "+yytext() );  return new Symbol(sym.decimal,yycolumn,yyline,yytext());}
//<YYINITIAL> {cadena}    {System.out.println("cadena: "+yytext() );  return new Symbol(sym.cadena,yycolumn,yyline,yytext());}
<YYINITIAL> {id}        {System.out.println("identificador: "+yytext() ); return  new Symbol(sym.id,yycolumn,yyline,yytext());}



"("         {return new Symbol(sym.Apar,yycolumn,yyline,yytext());} 
")"         {return new Symbol(sym.Cpar,yycolumn,yyline,yytext());}
"*"         {return new Symbol(sym.por,yycolumn,yyline,yytext());} 
"+"         {return new Symbol(sym.mas,yycolumn,yyline,yytext());}  
","         {return new Symbol(sym.cma,yycolumn,yyline,yytext());}
"-"         {return new Symbol(sym.menos,yycolumn,yyline,yytext());} 
"."         {return new Symbol(sym.punto,yycolumn,yyline,yytext());} 
"/"         {return new Symbol(sym.div,yycolumn,yyline,yytext());} 
":"         {return new Symbol(sym.dosp,yycolumn,yyline,yytext());}
";"         {return new Symbol(sym.pyc,yycolumn,yyline,yytext());} 
"?"         {return new Symbol(sym.interroga,yycolumn,yyline,yytext());}
"{"         {return new Symbol(sym.Allav,yycolumn,yyline,yytext());} 
"}"         {return new Symbol(sym.Cllav,yycolumn,yyline,yytext());}
"|"         {return new Symbol(sym.barra,yycolumn,yyline,yytext());}
"["    {}
"]"    {}
"\"" {yybegin(STR);} //estado para STR
{Comentario} { /*Se ignora.*/} 
{ComentarioMulti} { /*Se ignora.*/}

/* Recoleccion de errores*/
. 
{ System.err.println("Error lexico: "+yytext()+ " Linea: "+(yyline+1)+" Columna: "+(yycolumn+1)); 


}