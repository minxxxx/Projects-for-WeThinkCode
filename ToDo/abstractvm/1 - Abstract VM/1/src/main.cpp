/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:37:30 by jleblanc          #+#    #+#             */
/*   Updated: 2017/03/06 20:06:15 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVM.hpp"

#define TRACER(X) { if(verbose) X; }


#define _verbose avm._verbose

void	print_help (void)
{
	std::cout << "	\n	./avm [--verbose] [-t] [-f file]\n\n";
	std::cout << " 		--verbose 	: the machine tells you what it is doing\n";
	std::cout << " 		-t 		: Enter the commands from the terminal. Once finished, enter ;; \n";
	std::cout << " 		-f file 	: file containing the commands terminating by exit \n\n"; 
	std::cout << " 		options -t and -f are mutually exclusive\n\n";
}

int main(int argc, char **argv)
{
	bool		verbose = false;
	bool		terminal = false;
	bool		file = false;
	std::string	comfile;

	try{
		AVM 		&avm = AVM::get();

		if (argc < 2 || argc > 4)
		{
			print_help ();
			return (-1);
		}
		while (argc > 1)
		{
			if(std::string(argv[1]).compare("--verbose") == 0)
				verbose = true;
			else if(std::string(argv[1]).compare("-t") == 0)
			{
				terminal = true;
				file = !terminal;
			}
			else if(std::string(argv[1]).compare("-f") == 0)
			{
				file = true;
				terminal = !file;
				argc--;
				if (argc > 1)
				{
					argv++;
					comfile = std::string(argv[1]);
				}
				else
				{
					print_help ();
					return (-1);
				}		 
			}
			else
			{
				print_help ();
				return (-1);
			}
			argc--;
			if (argc > 1)
				argv++;
		}
		if ( terminal && file)
		{
			print_help ();
			return (-1);
		}

		std::ifstream 	ifs;
		std::istream 	*pCin = &std::cin;
	
		if (file)
		{
		 	ifs.open (comfile, std::ifstream::in);
			if (!ifs.good ())
			{
				std::cout << "\nError:	Unable to open file  " << comfile << " !!"<< std::endl;
				print_help ();
				return (-1);
			}
			pCin = &ifs; 	
		}


		if(ifs.good() && avm.analyse(*pCin, verbose, terminal))
		{
			ifs.close();
			if (avm.run(verbose)){
				TRACER( std::cout << "execution OK" << std::endl);
				return 0;
			}else{
				TRACER( std::cout << "execution KO" << std::endl);
			}

			return (-1);
		}else{
			TRACER( std::cout << "Retour Parse KO" << std::endl);
		}

		if (file)
			ifs.close();

	}catch(AVMException const & e){
		std::cout << "AVMException/" 
			<< e.what() << std::endl;
	}catch(std::exception const & e){
		std::cout << "fatal exception intercepted : " << e.what() << std::endl;
	}

	return (0);
}

