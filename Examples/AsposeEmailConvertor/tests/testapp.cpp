#include <iostream>
#include <AsposeEmailConvertor.h>


void main(int argc, char* argv[])
{
   std::cout << "hello world: " << argc << std::endl;

// C:\project\License2024\"Aspose.Email.C++.lic" 
   std::string result = LoadLicense("C:\\project\\License2024\\Aspose.Email.C++.lic");	

   std::cout << "Result:" << result << std::endl;


   if (argc == 2)
   {
	auto result = ConvertMailMessageToHtml(argv[1]);
	std::cout << "Converting " << argv[1] << std::endl;
	std::cout << "Result" << std::endl << result << std::endl;
   }
}