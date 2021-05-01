using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace NET.LAB.TCP.SERVER
{
    class Program
    {
        static void Main(string[] args)
        {
            const string ip = "192.168.38.178";
            const int port = 25565;

            var TcpEndPoint = new IPEndPoint(IPAddress.Parse(ip), port);

            var TcpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            TcpSocket.Bind(TcpEndPoint);
            TcpSocket.Listen(10);

            while (true)
            {
                var listener = TcpSocket.Accept();
                var buffer = new byte[256];
                var size = 0;
                
                var data = new StringBuilder();
                do
                {
                    size = listener.Receive(buffer);

                    //listener.Send(buffer);
                    data.Append(Encoding.UTF8.GetString(buffer, 0, size));

                }
                while (listener.Available > 0);

                Console.WriteLine(data);
                //listener.Send(Encoding.UTF8.GetBytes(data));
                
                listener.Send(Encoding.UTF8.GetBytes("Успех!"));

                listener.Shutdown(SocketShutdown.Both);
                listener.Close();

            }
        }
    } 
}
