#pragma once
#include <iostream>
#include <string>

namespace book_store {
class sales_item {
friend std::istream& operator>>(std::istream&, sales_item&);
friend std::ostream& operator<<(std::ostream&, const sales_item&);
friend bool operator<(const sales_item&, const sales_item&);
friend bool
operator==(const sales_item&, const sales_item&);
friend sales_item operator+(const sales_item&, const sales_item&);
 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
 public:
  sales_item() = default;
  sales_item(const std::string &book) : bookNo(book) {}
  sales_item(std::istream &is) {is >> *this;}
  sales_item& operator+= (const sales_item&);
  std::string isbn() const {return bookNo;}
  double avg_price() const;
};

inline bool
compareIsbn(const sales_item &lhs, const sales_item &rhs) {
  return lhs.isbn() == rhs.isbn();
}

sales_item
operator+(const sales_item &lhs, const sales_item &rhs) {
  sales_item ret(lhs);
  ret += rhs;
  return ret;
}

inline bool
operator==(const sales_item &lhs, const sales_item &rhs) {
  return ((lhs.units_sold == rhs.units_sold) &&
          (lhs.revenue == rhs.revenue) &&
	  (lhs.isbn() == rhs.isbn())
	 );
}

inline bool
operator!=(const sales_item &lhs, const sales_item &rhs) {
  return !(lhs == rhs);
}

sales_item& sales_item::operator+=(const sales_item& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::istream&
operator>>(std::istream& in, sales_item& s) {
  double price;
  in >> s.bookNo >> s.units_sold >> price;
  if (in) {
    s.revenue = s.units_sold * price;
  } else {
    s = sales_item();
  }
  return in;
}

std::ostream&
operator<<(std::ostream& out, const sales_item& s) {
  out << s.isbn() << " " << s.units_sold << " "
      << s.revenue << " " << s.avg_price();
  return out;
}

double
sales_item::avg_price() const {
  if (units_sold) {
    return revenue / units_sold;
  } else {
    return 0;
  }
}

} // namespace book_store

