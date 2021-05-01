using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace NET.LAB.TCP.CLIENT
{
    class Program
    {
        static void Main(string[] args)
        {

            SendMessageFromSocket();
        }
        static void SendMessageFromSocket()
        {
            const string ip = "213.111.76.142";
            const int port = 25565;

            var TcpEndPoint = new IPEndPoint(IPAddress.Parse(ip), port);

            var TcpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            Console.WriteLine("Введите сообщение:");
            var message = Console.ReadLine();
            var data = Encoding.UTF8.GetBytes(message);
            TcpSocket.Connect(TcpEndPoint);
            TcpSocket.Send(data);
            var buffer = new byte[256];
            var size = 0;
            var answer = new StringBuilder();
            do
            {
                size = TcpSocket.Receive(buffer);
                answer.Append(Encoding.UTF8.GetString(buffer, 0, size));

            }
            while (TcpSocket.Available > 0);
            Console.WriteLine(answer.ToString());
            // TcpSocket.Shutdown(SocketShutdown.Both);
            //   TcpSocket.Close();


            SendMessageFromSocket();
            TcpSocket.Shutdown(SocketShutdown.Both);
            TcpSocket.Close();

        }
    }
}
