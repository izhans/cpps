#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private :
		enum Level {
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			UNKNOWN
		};

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		
		Level getLevel(std::string level);
	public :
		Harl(void);
		~Harl(void);
		void complain( std::string level );
};

#endif
