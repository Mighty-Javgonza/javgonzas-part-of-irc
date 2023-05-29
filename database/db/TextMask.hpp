#ifndef TEXT_MASK_HPP
# define TEXT_MASK_HPP

# include <string>

class TextMask
{
	public:
		TextMask(void);
		TextMask(std::string const &mask);
		TextMask(TextMask const &rhs);
		~TextMask(void);
		TextMask	&operator=(TextMask const &rhs);
		bool	Pass(std::string const &candidate) const;
	private:
		std::string	__mask;
};
#endif

