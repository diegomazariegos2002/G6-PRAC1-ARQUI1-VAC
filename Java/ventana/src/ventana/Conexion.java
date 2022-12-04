/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ventana;

import com.fazecast.jSerialComm.SerialPort;
import java.io.IOException;

/**
 *
 * @author fabian
 */
public class Conexion {

    private SerialPort puertoSerie;

    public boolean conectar(int indice) {
        puertoSerie = SerialPort.getCommPorts()[indice];
        puertoSerie.openPort();
        puertoSerie.setComPortParameters(9600, 8, 1, 0);
        puertoSerie.setComPortTimeouts(SerialPort.TIMEOUT_WRITE_BLOCKING, 0, 0);
        return this.estaConectado();
    }
    
    public boolean estaConectado(){
        return puertoSerie.isOpen();
    }

    public boolean desconectar() {
        return puertoSerie.closePort();
    }

    public boolean enviarTexto(String texto) {
        try {
            puertoSerie.getOutputStream().write(texto.getBytes());
            puertoSerie.getOutputStream().flush();
            return true;
        } catch (IOException ex) {
            return false;
        }
    }

    public static SerialPort[] getPuertos() {
        return SerialPort.getCommPorts();
    }

}
