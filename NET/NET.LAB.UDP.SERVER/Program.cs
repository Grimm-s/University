using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;


namespace NET.LAB.UDP.SERVER
{
    class Program
    {
        static void Main(string[] args)
        {
            const string ip = "192.168.38.178";
            const int port = 25566;

            var UdpEndPoint = new IPEndPoint(IPAddress.Parse(ip), port);

            var UdpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

            UdpSocket.Bind(UdpEndPoint);
            while (true)
            {
                var buffer = new byte[256];
                var size = 0;
                var data = new StringBuilder();
                EndPoint SenderEndPoint = new IPEndPoint(IPAddress.Any, 0);
                do
                {

                    size = UdpSocket.ReceiveFrom(buffer, ref SenderEndPoint);
                    data.Append(Encoding.UTF8.GetString(buffer,0,size));
                }
                while (UdpSocket.Available > 0);
                UdpSocket.SendTo(Encoding.UTF8.GetBytes("Сообщение получено!"), SenderEndPoint);
                Console.WriteLine(data);
            }
            UdpSocket.Shutdown(SocketShutdown.Both);
            UdpSocket.Close();


            //UdpSocket.Shutdown(SocketShutdown.Both);
            //UdpSocket.Close();


        }
    }
}
