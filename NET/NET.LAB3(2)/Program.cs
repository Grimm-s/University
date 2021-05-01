using System;
using System.IO;
using System.Text;
using System.Net;
using System.Web;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Threading;

namespace NET.LAB3_2_
{
    class Program
    {
        public static string path1 = @"C:\Users\Admin\source\repos\NET.LAB3(2)\wwwroot\index2.txt"; 
        public static string path2 = @"C:\Users\Admin\source\repos\NET.LAB3(2)\wwwroot\images\5a2e7c35899fc192cdf20846090432e3.jpg";
        public static string CheckTestUrl(HttpListener listener, HttpListenerRequest request)
        {
            /* if (request.Url == "http://localhost:8888/image.jpg/")
             {
                 //listener.Abort();
                 return path2;
             }
             else
             {
                 return path1;
             }*/
            HttpRequestHeader.ContentType =    
            return path2;
        }
        static void Main(string[] args)
        {           
            //string path1 = @"C:\Users\Admin\source\repos\NET.LAB3(2)\wwwroot\index2.txt";
            //string path2 = @"C:\Users\Admin\source\repos\NET.LAB3(2)\wwwroot\images\5a2e7c35899fc192cdf20846090432e3.jpg";
            var listener = new HttpListener();
            // установка адресов прослушки
            listener.Prefixes.Add("http://localhost:8888/index2.html/");
            listener.Prefixes.Add("http://localhost:8888/image.jpg/");
            while (true)
            {
                listener.Start();
                Console.WriteLine("Ожидание подключений...");
                // метод GetContext блокирует текущий поток, ожидая получение запроса 
                var context = listener.GetContext();

                var request = context.Request;
                // получаем объект ответа
                var types = request.AcceptTypes;
                if (types != null)
                {
                    Console.WriteLine("Acceptable MIME types:");
                    foreach (var s in types)
                    {
                        Console.WriteLine(s);
                    }
                }
                Console.WriteLine(request.ContentType);
                var response = context.Response;

                // создаем ответ в виде кода html     

                // System.IO.StreamReader streamReader = new StreamReader($"{path}");
                //string TheString; //= streamReader.ReadLine();
                // using (FileStream fstream = File.OpenRead($"{path2}"))
                // {
                // преобразуем строку в байты
                //   byte[] array = new byte[fstream.Length];
                // считываем данные
                //  fstream.Read(array, 0, array.Length);
                // декодируем байты в строку
                //  TheString = System.Text.Encoding.UTF8.GetString(array);
                // }
                //string TheHtmlString = WebUtility.HtmlDecode(TheString);
                //Response(response);
                //CheckTestUrl(HttpListener listener, HttpListenerRequest request)
                //byte[] imageBytes = File.ReadAllBytes(@"C:\Users\Admin\source\repos\NET.LAB3(2)\wwwroot\images\5a2e7c35899fc192cdf20846090432e3.jpg");
                var buffer = File.ReadAllBytes(CheckTestUrl( listener, request));//@"C:\Users\Admin\source\repos\NET.LAB3(2)\wwwroot\index2.txt");//= System.Text.Encoding.UTF8.GetBytes(TheString);
                // получаем поток ответа и пишем в него ответ    
                response.ContentLength64 = buffer.Length;
               // response.ContentType = "image/jpeg";
                var output = response.OutputStream;
                output.Write(buffer, 0, buffer.Length);
                // закрываем поток
                output.Close();
                // останавливаем прослушивание подключений*/
                listener.Stop();
                Console.WriteLine("Обработка подключений завершена");     
                
            }
        }
    }
}





