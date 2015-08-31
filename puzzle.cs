using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace ConsoleApplication7
{
    class Funciones
    {

        static List<List<int>> explorados = new List<List<int>>();

        public bool yaExiste(int a, int b, int c, int d, int e, int f, int g, int h, int j)
        {
            for (int i = 0; i < explorados.Count(); i++)
            {
                if (explorados[i][0]==a &&
                    explorados[i][1]==b &&
                    explorados[i][2]==c &&
                    explorados[i][3]==d &&
                    explorados[i][4]==e &&
                    explorados[i][5]==f &&
                    explorados[i][6]==g &&
                    explorados[i][7]==h &&
                    explorados[i][8]==j)
                    return true;
            }

            return false;
        }



        public void agregarExplorado(List<int> tablero)
        {
            List<int> aux = new List<int>();

            for (int i = 0; i < tablero.Count(); i++)
            {
                aux.Add(0);
                aux[i] = tablero[i];
            }
            explorados.Add(aux);
        }

        public bool Ordenar(List<int> tablero)
        {
          // Thread.Sleep(500);
          //  Console.WriteLine();
         //  Console.WriteLine("ITERACION");

            // accion=0   arriba
            // accion=1   izquierda
            // accion=2   abajo
            // accion=3   derecha
            // Console.WriteLine("o");
           // int[] tableroOriginal = tablero;

          for (int i = 0; i < tablero.Count(); i++)
            {
                if (i % 3 == 0)
                    Console.WriteLine();
                if (tablero[i] == -1)
                    Console.Write("  ");
                else
                    Console.Write(" " + tablero[i]);
            }
                    Console.WriteLine();
            if (tablero[0] == 0 && tablero[1] == 1 && tablero[2] == 2 && tablero[3] == 3 && tablero[4] == 4 && tablero[5] == 5
                && tablero[6] == 6 && tablero[7] == 7 )
            {
                Console.WriteLine("lo logre");
                return true;

            }

            if (yaExiste(tablero[0], tablero[1], tablero[2], tablero[3], tablero[4], tablero[5], tablero[6], tablero[7], tablero[8]))
            {
                return false;
            }


          // explorados.Add(tablero);
            agregarExplorado(tablero);
         /*  Console.WriteLine("Lista de explorados: " + explorados.Count());
           for (int i = 0; i < explorados.Count(); i++)
           {
               for (int j = 0; j < 9; j++)
               {
                   Console.Write(" " + explorados[i][j]);

               }
               Console.WriteLine();

           }*/





            int pos = -1;
            for (int i = 0; i < tablero.Count(); i++)
            {
                if (tablero[i] == -1)
                {
                    pos = i;
                    break;
                }
            }


            //moverhaciaarriba

            if (pos > 2)
            {
                //pos = posicion de -1 en el arreglo


                List<int> auxTab = new List<int>();
                auxTab.Clear();
                auxTab.Add(tablero[0]);
                auxTab.Add(tablero[1]);
                auxTab.Add(tablero[2]);
                auxTab.Add(tablero[3]);
                auxTab.Add(tablero[4]);
                auxTab.Add(tablero[5]);
                auxTab.Add(tablero[6]);
                auxTab.Add(tablero[7]);
                auxTab.Add(tablero[8]);
                int aux = -2;
                aux = auxTab[pos - 3];
                auxTab[pos - 3] = auxTab[pos];
                auxTab[pos] = aux;
                if (Ordenar(auxTab) == true)
                    return true;


            }

            //moverhaciaabajo

            if (pos < 6)
            {
                //pos = posicion de -1 en el arreglo
                List<int> auxTab = new List<int>();
                auxTab.Clear();
                auxTab.Add(tablero[0]);
                auxTab.Add(tablero[1]);
                auxTab.Add(tablero[2]);
                auxTab.Add(tablero[3]);
                auxTab.Add(tablero[4]);
                auxTab.Add(tablero[5]);
                auxTab.Add(tablero[6]);
                auxTab.Add(tablero[7]);
                auxTab.Add(tablero[8]);
                int aux = -2;
                aux = auxTab[pos + 3];
                auxTab[pos + 3] = auxTab[pos];
                auxTab[pos] = aux;
                if (Ordenar(auxTab) == true)
                    return true;
            }

            //moverhaciaizquierda

            if (pos != 0 && pos != 3 && pos != 6)
            {
                //pos = posicion de -1 en el arreglo
                List<int> auxTab = new List<int>();
                auxTab.Clear();
                auxTab.Add(tablero[0]);
                auxTab.Add(tablero[1]);
                auxTab.Add(tablero[2]);
                auxTab.Add(tablero[3]);
                auxTab.Add(tablero[4]);
                auxTab.Add(tablero[5]);
                auxTab.Add(tablero[6]);
                auxTab.Add(tablero[7]);
                auxTab.Add(tablero[8]);
                int aux = -2;
                aux = auxTab[pos - 1];
                auxTab[pos - 1] = auxTab[pos];
                auxTab[pos] = aux;
                if (Ordenar(auxTab) == true)
                    return true;
            }

            //moverhaciaderecha

            if (pos != 2 && pos != 5 && pos != 8)
            {
                //pos = posicion de -1 en el arreglo
                List<int> auxTab = new List<int>();
                auxTab.Clear();
                auxTab.Add(tablero[0]);
                auxTab.Add(tablero[1]);
                auxTab.Add(tablero[2]);
                auxTab.Add(tablero[3]);
                auxTab.Add(tablero[4]);
                auxTab.Add(tablero[5]);
                auxTab.Add(tablero[6]);
                auxTab.Add(tablero[7]);
                auxTab.Add(tablero[8]);
                int aux = -2;
                aux = auxTab[pos + 1];
                auxTab[pos + 1] = auxTab[pos];
                auxTab[pos] = aux;
                if (Ordenar(auxTab) == true)
                    return true;
            }


            return false;

        }



    }


    class Program
    {
        static void Main(string[] args)
        {
            int[] tablero = new int[9];
      List<int> tab = new List<int>();
            tablero = new int[] { 0, 1, 2, 3, 4, -1, 6, 7, 5 };
            // tablero = new int[] { 0, 1, 2, 3, 4, 5, 6, -1, 7 };
            for (int i = 0; i < tablero.Count(); i++)
            {
                tab.Add(tablero[i]);
            }
            Funciones fun = new Funciones();

            fun.Ordenar(tab);

            //Ordenar(tablero, explorados);
            Console.ReadLine();

        }
    }
}
