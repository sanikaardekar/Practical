for $x in doc("C:\Users\SAMEER\OneDrive\Desktop\CP\adbms\books.xml")/catalog/book
where $x/price>30
order by $x/title
return $x
