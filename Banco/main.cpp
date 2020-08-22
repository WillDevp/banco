#include <iostream>
#include <cmath>
#include <ctime>

using namespace ::std;
/*
 * *****************************
 * Variabales Globales
 */

struct nodo {
    long identificacion;
    string nombreUsuario;
    char genero;
    string fechaDeNacimineto;
    long numeroDeCuenta;
    long abonoAcuenta;
    long cantRetiro;
    long saldo;


    nodo *siguiente;
    nodo *atras;
} *primero, *ultimo;

void insertarDatosUsuario();

void sucursalVirtualCuentaPersonal();

void sucursalVirtualRealizarDeposito();

void sucursalVirtualRetirosBancarios();

void sucursalVirtualConsignar();

void operacionesExternas();

void sucursalVirtualmodificarDatosCliente();

void sucursalVirtualEliminarCliente();

void sucursalVirtualEliminarNumeroDeCuenta();

void sucursalvirtualpilaDatosHombre();

void sucursalVirtualPilaDeSaldo();

void sucursalVirtualColaRetiro();


void ver();

int main() {
    int opcion = 0;
    do {
        cout << "\n|----------------------------------------------------------------------------------------------|";
        cout << "\n|                                   BANCO                                                      |";
        cout << "\n|----------------------------------------------------------------------------------------------|";
        cout << "\n| 1. Registrar los datos del usuario    | 2. Ingresar a la sucrusal virtual                    |";
        cout << "\n| 3. Ver todos los clientes del Banco   | 4. Realizar consultas                                |";
        cout << "\n| 5. Salir del programa                 |                                                      |";
        cout << "\n|----------------------------------------------------------------------------------------------|";
        cout << "\n\n Por favor Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "\n\n El proceso de registro se esta ejecutando correctamente....\n\n";
                insertarDatosUsuario();
                break;
            case 2:
                cout << "\n\nRedireccionando a la sucursal virtual.... \n\n";

                sucursalVirtualCuentaPersonal();
                break;
            case 3:
                cout << "\n\n Mostrar los usuraios registrados\n\n";
                ver();
                break;
            case 4:
                operacionesExternas();
                break;
            default:
                cout << "\n\n Opcion no valida intente de nuevo\n\n";
        }
    } while (opcion != 5);
    return 0;
}

//Lista doblemente ligada
void insertarDatosUsuario() {
    nodo *nuevo = new nodo();
    cout << "Ingrese el ID: ";
    cin >> nuevo->identificacion;
    cout << "Ingrese el nombre del usuario: ";
    cin >> nuevo->nombreUsuario;
    cout << "\nEstimado cliente para ingresar su genero debe ingresarlo asi:\n"
            "si es hombre 'm' y si es mujer 'f'. \n"
            "estos datos se digitan de esta manra para calculos posteriores :-)\n\n";
    cout << "Ingrese el genero: ";
    cin >> nuevo->genero;
    cout << "Ingrese su fecha de nacimiento asi: /DD/MM/DDDD: ";
    cin >> nuevo->fechaDeNacimineto;

    cout << "\n Señor usuario recuerde que:\n\n"
            "1. Su número de cuenta bancaria se generara automaticamente por el sistema\n"
            "2. Si desea realizar transacciones primero debe ingresar a la sucursal virtual en el menu principal\n"
            "3. Recuerde que para nosotros es un placer servirle :-) :-)\n\n";
    srand(time(NULL));
    nuevo->numeroDeCuenta = rand();
    cout << "El número de cuenta fue creado correctamente: " << nuevo->numeroDeCuenta << endl << "\n\n";
    cout
            << "\n\n Querido usuario por favor tenga en cuenta que recordar su numero de cuenta bancaria, esto muy importante para nosotros\n"
               "le sugerimos copiar el este numero ya que solo estara activo mientras el programa este en ejecucion\n\n";

    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
        primero->siguiente = primero;
        primero->atras = ultimo;
    } else {
        ultimo->siguiente = nuevo;
        nuevo->atras = ultimo;
        nuevo->siguiente = primero;
        ultimo = nuevo;
        primero->atras = ultimo;
    }
    cout << "\n cliente igresado correctamente..........\n\n";
}


void sucursalVirtualCuentaPersonal() {
    nodo *actual = new nodo();
    actual = primero;
    bool NumeroDeCuentaEncontrado = false;
    long NumeroDeCuentaABuscar;
    long num;
    cout << " Ingrese su numero de identificación: ";
    cin >> NumeroDeCuentaABuscar;
    cout << " Ingrese su numero de cuenta Bancaria para verificar: ";
    cin >> num;
    if (primero != NULL) {
        while (actual != NULL && NumeroDeCuentaEncontrado != true) {

            if (actual->identificacion == NumeroDeCuentaABuscar && actual->numeroDeCuenta == num) {
                cout << "\n El usuario con numero de cuenta: " << "[ " << actual->identificacion << " ]" << "[ "
                     << actual->numeroDeCuenta << " ]"
                     << " Fue encontrado :-)";
                NumeroDeCuentaEncontrado = true;
                int opcion = 0;
                do {
                    cout
                            << "\n|------------------------------------------------------------------------------------------------------------------------|";
                    cout
                            << "\n|                                        BANCO                                                                           |";
                    cout
                            << "\n|        BIENVENIDO AL GESTOR VIRTUAL DE SU CUENTA PERSONAL " << "[ "
                            << actual->nombreUsuario << " ]"
                            << "[ " << actual->identificacion << " ]"
                            << "                                                     |";
                    cout
                            << "\n|------------------------------------------------------------------------------------------------------------------------|";
                    cout
                            << "\n|        1. Recargar cuenta                      |              2. Retirar                                       |";
                    cout
                            << "\n|        3. Realizar una transaccion             |              4. Ver saldo total en la cuenta                  |";
                    cout
                            << "\n|        5. Actualizar datos personales          |              6. Eliminar mis datos personales                 |";
                    cout
                            << "\n|        7. Eliminar cuenta bancaria             |              8. Salir de la sucursal                          |";
                    cout
                            << "\n|        7. Salir                                |              8. Salir de la sucursal                          |";
                    cout
                            << "\n|-------------------------------------------------------------------------------------------------------------------------|";
                    cout << "\n\n Por favor Ingrese una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                        case 1:
                            sucursalVirtualRealizarDeposito();
                            break;
                        case 2:
                            sucursalVirtualRetirosBancarios();
                            break;
                        case 3:
                            sucursalVirtualConsignar();
                            break;
                        case 4:
                            cout << "Su saldo es de: " << actual->saldo << "\n";
                            break;
                        case 5:
                            sucursalVirtualmodificarDatosCliente();
                            break;
                        case 6:
                            sucursalVirtualEliminarCliente();
                            break;
                        case 7:
                            sucursalVirtualEliminarNumeroDeCuenta();
                        default:
                            cout << "\n\n Opcion no valida intente de nuevo\n\n";
                    }

                } while (opcion != 7);
            }
            actual = actual->siguiente;
            sucursalVirtualEliminarCliente();
        }
        if (!NumeroDeCuentaEncontrado) {
            cout << "\n Lo sentimos el dato que ingreso no se encunetra registrado :-(\n\n";
        }
    } else {
        cout << "\n Lo sentimos no hay usuarios en la lista del Banco\n\n";
    }
}

void operacionesExternas() {
    nodo* actual = new nodo();
    actual = primero;
    int opcion = 0;
    do {
        cout << "\n|----------------------------------------------------------------------------------------------|";
        cout << "\n|                                   BANCO                                                      |";
        cout << "\n|----------------------------------------------------------------------------------------------|";
        cout << "\n| 1. Ver Pila de hombres                | 2. Ver pila de saldo                                 |";
        cout << "\n| 3. Ver cola de retiro                 | 4. Salir del programa                                |";
        cout << "\n|----------------------------------------------------------------------------------------------|";
        cout << "\n\n Por favor Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "\n\n El proceso de pila se esta ejecutando correctamente....\n\n";
                    sucursalvirtualpilaDatosHombre();
                break;
            case 2:
                cout << "\n\n El proceso de pila se esta ejecutando correctamente....\n\n";
                sucursalVirtualPilaDeSaldo();
                break;
            case 3:
                sucursalVirtualColaRetiro();
                break;
            default:
                cout << "\n\n Opcion no valida intente de nuevo\n\n";
        }
    } while (opcion != 4);
}

void sucursalVirtualRealizarDeposito() {
    nodo *actual = new nodo();
    actual = primero;
    bool validarcuenta = false;
    long numeroDeCuentaAencontrar;
    cout << "Querido cliente por temas temas de seguridad solicitamos ingrese su cuenta bancarianuevamente :-)\n";
    cout << " Ingrese su numero de cuenta Bancaria para verificar: ";
    cin >> numeroDeCuentaAencontrar;
    if (primero != NULL) {
        do {
            if (actual->numeroDeCuenta == numeroDeCuentaAencontrar) {
                cout << "Su cuenta ha sido validada correctamente\n\n";
                cout << "Por favor digite la cantidad de dinero que desea depositar\n\n";
                cin >> actual->abonoAcuenta;
                actual->saldo = actual->saldo + actual->abonoAcuenta;
                cout << "Felicidades el deposito se ha generado correctamente\n";
                cout << "El deposito relizado es de: " << actual->saldo;
                validarcuenta = true;
            }
            actual = actual->siguiente;
        } while (actual != primero && validarcuenta != true);
        if (!validarcuenta) {
            cout << "\n Lo sentimos no se encuentra el numero de cuenta:-(\n\n";
        }
    } else {
        cout << "\nla lista del Banco se encuentra vacia\n\n";
    }

}

void sucursalVirtualRetirosBancarios() {
    nodo *actual = new nodo();
    actual = primero;
    bool validarcuenta = false;
    long numeroDeCuentaAencontrar;
    cout << "Querido cliente por temas temas de seguridad solicitamos ingrese su cuenta bancarianuevamente :-)\n";
    cout << " Ingrese su numero de cuenta Bancaria para verificar: ";
    cin >> numeroDeCuentaAencontrar;
    if (primero != NULL) {
        do {
            if (actual->numeroDeCuenta == numeroDeCuentaAencontrar) {
                cout << "Por favor digite la cantidad de dinero que desea consignar\n\n";
                cin >> actual->cantRetiro;
                if (actual->cantRetiro > actual->abonoAcuenta) {
                    cout << "Usted no cuenta con los fondos suficientes para realizar esta operación";
                } else {
                    actual->saldo = actual->saldo - actual->cantRetiro;
                    cout << "Felicidades el deposito se ha generado correctamente\n";
                    cout << "Saldo actual en la cuenta " << actual->saldo;
                }
                validarcuenta = true;
            }
            actual = actual->siguiente;
        } while (actual != primero && validarcuenta != true);
        if (!validarcuenta) {
            cout << "\n Lo sentimos no se encuentra el numero de cuenta:-(\n\n";
        }
    } else {
        cout << "\nla lista del Banco se encuentra vacia\n\n";
    }
}

void sucursalVirtualConsignar() {
    nodo *actual = new nodo();
    actual = primero;
    long cuentaBuscar, cuentaAConsignar, valorAconsignar, nuevoSaldo, nuevoSaldoAguardar;
    cout << "Por favor ingrese su numero de cuenta: ";
    cin >> cuentaBuscar;
    cout << "Por favor digite el número de cuenta al que desea consignar\n\n";
    cin >> cuentaAConsignar;
    if (primero != NULL) {

        cout << "Su cuenta ha sido validada correctamente\n\n";
        cout << "Por favor digite el valor que desea consignar\n\n";
        cin >> valorAconsignar;
        if (actual->saldo > valorAconsignar) {
            nuevoSaldo = actual->saldo - valorAconsignar;
            actual->saldo = nuevoSaldo;

            cout << "Querido cliente su trasaccion ha sido realizada correctamente";
            cout << "Usted cuenta con un saldo actual de: \n" << nuevoSaldo;


        }
        else {
            cout << "Lo sentimos su saldo actual no es suficiente para realizar esta operacion :-(";
        }
        if(cuentaAConsignar){
            nuevoSaldoAguardar = actual->saldo + valorAconsignar;
            actual->saldo = nuevoSaldoAguardar;
        }
        actual = actual->siguiente;
    }

}

void sucursalVirtualmodificarDatosCliente() {
    nodo *actual = new nodo();
    actual = primero;
    bool clienteEncontrado = false;
    long identificacionABuscar;
    string opcion;
    cout << "\nIngrese la identificacion del cliente que desea modificar: ";
    cin >> identificacionABuscar;
    if (primero != NULL) {
        do {
            if (actual->identificacion == identificacionABuscar) {
                cout << "\nEl cliente fue encontrado satisfactoriamente: ";
                cout << "\nPor favor ingrese un nuevo nombre: ";
                cin >> actual->nombreUsuario;
                cout << "\nPor favor ingrese un nuevo genero: ";
                cin >> actual->genero;
                cout << "\nPor favor ingrese una nueva fecha de nacimiento: ";
                cin >> actual->fechaDeNacimineto;
                cout
                        << "Estimado cliente para continuar el proceso de debe confirmar si desea modificar su numero de cuenta bancaria"
                           " recuerde que para nosotros el manejo de sus datos personales es muy importante \n\n";

                cout << "Por favor dijite SI/NO para continuar:\n";
                cin >> opcion;
                if (opcion == "SI") {
                    cout << "\n Por favor dijite el nuevo numero de cuenta que desea: ";
                    cin >> actual->numeroDeCuenta;
                } else {
                    cout << "Su numeor de cuenta no ha sido modificado\n";
                }
                cout << "\nCliente modificado correctamente\n";


                clienteEncontrado = true;
            }
            actual = actual->siguiente;
        } while (actual != primero && clienteEncontrado != true);
        if (!clienteEncontrado) {
            cout << "\nCliente no encontrado :-(\n";
        }
    } else {
        cout << "\n La lista del banco se encuentra vacia\n";
    }
}

void sucursalVirtualEliminarCliente() {
    nodo *actual = new nodo();
    actual = primero;
    nodo *anterior = new nodo();
    anterior = NULL;
    bool clienteEncontrado = false;
    long identificacionABuscar;
    cout << "\nIngrese la identificacion del cliente para eliminar: ";
    cin >> identificacionABuscar;
    if (primero != NULL) {
        do {
            if (actual->identificacion == identificacionABuscar) {
                cout << "\nEl cliente con la identificacion fue encontrado: \n";
                if (actual == primero) {
                    primero = primero->siguiente;
                    primero->atras = ultimo;
                    ultimo->siguiente = primero;
                } else if (actual == ultimo) {
                    ultimo = anterior;
                    ultimo->siguiente = primero;
                    primero->atras = ultimo;
                } else {
                    anterior->siguiente = actual->siguiente;
                    actual->siguiente->atras = anterior;
                }
                cout << "\nCliente eliminado correctamente\n";
                clienteEncontrado = true;
            }
            anterior = actual;
            actual = actual->siguiente;
        } while (actual != primero && clienteEncontrado != true);
        if (!clienteEncontrado) {
            cout << "\nCliente  no encontrado :-)\n";
        }
    } else {
        cout << "\n La lista del banco se encuentra vacia\n";
    }
}

void sucursalVirtualEliminarNumeroDeCuenta() {
    nodo *actual = new nodo();
    actual = primero;
    nodo *anterior = new nodo();
    anterior = NULL;
    bool seEncontro = false;
    long numeroDecuentaBuscar;
    cout << "\nIngrese el numero de cuenta para eliminar: ";
    cin >> numeroDecuentaBuscar;
    if (primero != NULL) {
        do {
            if (actual->numeroDeCuenta == numeroDecuentaBuscar) {
                cout << "\nLa cuenta fue encontrada";
                if (actual == primero) {
                    primero = primero->siguiente;
                    primero->atras = ultimo;
                    ultimo->siguiente = primero;
                } else if (actual == ultimo) {
                    ultimo = anterior;
                    ultimo->siguiente = primero;
                    primero->atras = ultimo;
                } else {
                    anterior->siguiente = actual->siguiente;
                    actual->siguiente->atras = anterior;
                }
                cout << "\nCuenta eliminada\n";
                seEncontro = true;
            }
            anterior = actual;
            actual = actual->siguiente;
        } while (actual != primero && seEncontro != true);
        if (!seEncontro) {
            cout << "\nCuenta no encontrada\n";
        }
    } else {
        cout << "\n La lista se encuentra vacia\n";
    }
}

void sucursalvirtualpilaDatosHombre() {
    nodo *actual = new nodo();
    actual = primero;
    if (primero != NULL) {
        do{
            if(actual->genero == 'm'){
                cout << "\n " << "[ " << actual->identificacion << " ]" << "[ " << actual->nombreUsuario << " ]"
                     << "[ " << actual->genero << " ]" << "[ " << actual->fechaDeNacimineto << " ]";
                actual = actual->siguiente;
            }
        }while (actual != NULL);
        }else {
        cout << "\n Lo sentimos la lista esta vacia\n\n";
    }
}

void sucursalVirtualPilaDeSaldo() {
    nodo *actual = new nodo();
    actual = primero;
    if (primero != NULL) {
        while (actual != NULL) {
            cout << "\n " << "[ " << actual->identificacion << " ]" << "[ " << actual->nombreUsuario << " ]"
                 << "[ " << actual->genero << " ]" << "[ " << actual->fechaDeNacimineto << " ]";
            actual = actual->siguiente;
        }
    } else {
        cout << "\n Lo sentimos la lista esta vacia\n\n";
    }
}

void sucursalVirtualColaRetiro() {
    nodo *actual = new nodo();
    actual = primero;
    if (primero != NULL) {
        do {
            if (actual->cantRetiro == true) {
                cout << actual->numeroDeCuenta << "  " << actual->nombreUsuario << "  " << actual->saldo << "  \n";
                actual = actual->siguiente;
            }
        } while (actual != primero);
    } else {
        cout << "\n La cola del banco se encuentra vacia\n";
    }
}

void ver() {
    nodo *actual = new nodo();
    actual = primero;
    if (primero != NULL) {
        while (actual != NULL) {
            cout << "\n " << "[ " << actual->identificacion << " ]" << "[ " << actual->nombreUsuario << " ]"
                 << "[ " << actual->genero << " ]" << "[ " << actual->fechaDeNacimineto << " ]";
            actual = actual->siguiente;
        }
    } else {
        cout << "\n Lo sentimos la lista esta vacia\n\n";
    }
}