/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;


namespace NET.LAB.UDP.CLIENT
{
    class Program
    {
        static void Main(string[] args)
        {
            const string ip = "91.201.168.35";// 213.111.76.142
            const int port = 25566;

            var UdpEndPoint = new IPEndPoint(IPAddress.Parse(ip), port);

            var UdpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

            UdpSocket.Bind(UdpEndPoint);
            while (true)
            {
                Console.WriteLine("Введите сообщение:");
                var message = Console.ReadLine();
                
                var ServerEndPoint = new IPEndPoint(IPAddress.Parse(ip), 25566);
                UdpSocket.SendTo(Encoding.UTF8.GetBytes(message),ServerEndPoint);

                var buffer = new byte[256];
                var size = 0;
                var data = new StringBuilder();
                EndPoint SenderEndPoint = new IPEndPoint(IPAddress.Parse(ip), 25566);
                do
                {
                     
                    size = UdpSocket.ReceiveFrom(buffer, ref SenderEndPoint);
                    data.Append(Encoding.UTF8.GetString(buffer,0,size));
                }
                while (UdpSocket.Available > 0);
               
                Console.WriteLine(data);
                
            }
            

        }
    }
}
*/
/*using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace NET.LAB.UDP.CLIENT
{
    class Chat
    {
        private static IPAddress remoteIPAddress;
        private static int remotePort;
        private static int localPort;

        [STAThread]
        static void Main(string[] args)
        {
            try
            {
                // Получаем данные, необходимые для соединения
                Console.WriteLine("Укажите локальный порт");
                localPort = Convert.ToInt16(Console.ReadLine());

                Console.WriteLine("Укажите удаленный порт");
                remotePort = Convert.ToInt16(Console.ReadLine());

                Console.WriteLine("Укажите удаленный IP-адрес");
                remoteIPAddress = IPAddress.Parse(Console.ReadLine());

                // Создаем поток для прослушивания
                Thread tRec = new Thread(new ThreadStart(Receiver));
                tRec.Start();

                while (true)
                {
                    Send(Console.ReadLine());
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Возникло исключение: " + ex.ToString() + "\n  " + ex.Message);
            }
        }

        private static void Send(string datagram)
        {
            // Создаем UdpClient
            UdpClient sender = new UdpClient();

            // Создаем endPoint по информации об удаленном хосте
            IPEndPoint endPoint = new IPEndPoint(remoteIPAddress, remotePort);

            try
            {
                // Преобразуем данные в массив байтов
                byte[] bytes = Encoding.UTF8.GetBytes(datagram);

                // Отправляем данные
                sender.Send(bytes, bytes.Length, endPoint);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Возникло исключение: " + ex.ToString() + "\n  " + ex.Message);
            }
            finally
            {
                // Закрыть соединение
                sender.Close();
            }
        }

        public static void Receiver()
        {
            // Создаем UdpClient для чтения входящих данных
            UdpClient receivingUdpClient = new UdpClient(localPort);

            IPEndPoint RemoteIpEndPoint = null;

            try
            {
                Console.WriteLine(
                   "\n-----------*******Общий чат*******-----------");

                while (true)
                {
                    // Ожидание дейтаграммы
                    byte[] receiveBytes = receivingUdpClient.Receive(
                       ref RemoteIpEndPoint);

                    // Преобразуем и отображаем данные
                    string returnData = Encoding.UTF8.GetString(receiveBytes);
                    Console.WriteLine(" --> " + returnData.ToString());
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Возникло исключение: " + ex.ToString() + "\n  " + ex.Message);
            }
        }
    }
}*/
/*using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace UdpClientApp
{
    class Program
    {

        static string remoteAddress = "91.201.168.35"; //= "127.0.0.1";// = "213.111.76.142" ; // хост для отправки данных
        static int remotePort ; // порт для отправки данных
        static int localPort; // локальный порт для прослушивания входящих подключений

        static void Main(string[] args)
        {
            
            try
            {
                Console.Write("Введите порт для прослушивания: "); 
                localPort = Int32.Parse(Console.ReadLine());
                //Console.Write("Введите удаленный адрес для подключения: ");
               // remoteAddress = Console.ReadLine(); 
                Console.Write("Введите порт для подключения: ");
                remotePort = Int32.Parse(Console.ReadLine()); 

                Thread receiveThread = new Thread(new ThreadStart(ReceiveMessage));
                receiveThread.Start();
                SendMessage(); 
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        private static void SendMessage()
        {
            UdpClient sender = new UdpClient(); 
            try
            {
                while (true)
                {
                    string message = Console.ReadLine();
                    byte[] data = Encoding.Unicode.GetBytes(message);
                    sender.Send(data, data.Length, remoteAddress, remotePort);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                sender.Close();
            }
        }

        private static void ReceiveMessage()
        {
            
            UdpClient receiver = new UdpClient(localPort);
            IPEndPoint remoteIp = new IPEndPoint(IPAddress.Parse(remoteAddress), remotePort);// null;
            try
            {
                while (true)
                {
                    byte[] data = receiver.Receive(ref remoteIp); 
                    string message = Encoding.Unicode.GetString(data);
                    Console.WriteLine("Собеседник: {0}", message);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                receiver.Close();
            }
        }
    }
}*/
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
 
namespace UdpClientApp
{
    class Program
    {
        static string remoteAddress; // хост для отправки данных
        static int remotePort; // порт для отправки данных
        static int localPort; // локальный порт для прослушивания входящих подключений

        static void Main(string[] args)
        {
            try
            {
                Console.Write("Введите порт для прослушивания: "); // локальный порт
                localPort = Int32.Parse(Console.ReadLine());
                Console.Write("Введите удаленный адрес для подключения: ");
                remoteAddress = Console.ReadLine(); // адрес, к которому мы подключаемся
                Console.Write("Введите порт для подключения: ");
                remotePort = Int32.Parse(Console.ReadLine()); // порт, к которому мы подключаемся

                Thread receiveThread = new Thread(new ThreadStart(ReceiveMessage));
                receiveThread.Start();
                SendMessage(); // отправляем сообщение
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        private static void SendMessage()
        {
            UdpClient sender = new UdpClient(); // создаем UdpClient для отправки сообщений
            try
            {
                while (true)
                {
                    string message = Console.ReadLine(); // сообщение для отправки
                    byte[] data = Encoding.Unicode.GetBytes(message);
                    sender.Send(data, data.Length, remoteAddress, remotePort); // отправка
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                sender.Close();
            }
        }

        private static void ReceiveMessage()
        {
            UdpClient receiver = new UdpClient(localPort); // UdpClient для получения данных
            IPEndPoint remoteIp = null; // адрес входящего подключения
            try
            {
                while (true)
                {
                    byte[] data = receiver.Receive(ref remoteIp); // получаем данные
                    string message = Encoding.Unicode.GetString(data);
                    Console.WriteLine("Собеседник: {0}", message);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                receiver.Close();
            }
        }
    }
}