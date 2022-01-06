#include "core/trace.hpp"
#include "core/network.hpp"

int main()
{
	int choice;

	while (true)
	{
		system("cls");

		std::cout << R"(
                                            
                                                            
                 *//                                          
             .*/****/.       ,***************                 
        *****************************************             
      ******(***************************************          
   .********%#***************************************         
   **************************************************.        
        ////**********************//******************        
                ////*************////*****************        
                   ////*******///////****************         
                       //*****///////*********************    
                          ***.          *********     ******* 
                        *****        ********             ****
                                                          ****
                                                      ,*****  
                             .*************************       

	)" << '\n';

		g_network = std::make_unique<network>();
		g_trace = std::make_unique<trace>();

		g_trace->m_fivem_path = g_trace->set_folder("Select FiveM Folder which contains FiveM.exe");
	
		if (g_trace->m_fivem_path != "")
		{
			while (true)
			{
				system("cls");

				std::cout << "  [Selected Folder]  " << g_trace->m_fivem_path << "\n" << std::endl;

				std::cout << "  [1]  :  " << "clean traces" << std::endl;
				std::cout << "  [2]  :  " << "enable network bypass" << std::endl;
				std::cout << "  [3]  :  " << "disable network bypass" << std::endl;
				std::cin >> choice;

				switch (choice)
				{
					case 1:
					{
						g_trace->setup();
					}
					break;
					case 2:
					{
						g_network->setup();
					}
					break;
					case 3:
					{
						g_network->destroy();
					}
					break;
				}

				system("Pause");
			}

		}
		else
		{
			std::cout << "  [Error]  :  " << "select valid folder for FiveM" << "\n" << std::endl;
		}

		system("Pause");
	}

}
