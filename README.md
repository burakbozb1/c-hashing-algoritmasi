C ile Hashing algoritması kullanarak verilerin saklanması ve verilere ulaşılması

Hashing algoritmasının kullanılması
Problem: Bu ödevde, bir kelimenin geçtiği dokümanları listeleyen bir sistem tasarlanacaktır. Bir
kelimenin hangi dokümanlarda geçtiğini bulmak için her seferinde bütün dokümanlara bakmak çok
zaman alıcıdır. Bunun yerine bu ödevde, yeni gelen bir dokümandaki kelimeler hashing ile bir sözlüğe
yerleştirilecek ve bir kelime arandığında yine hashing yöntemi ile sözlükte aranarak içinde yer aldığı
dokümanlar bulunacaktır. 


Kelimeleri hashlemek için horner methodundan faydalanılmıştır. Hash tablosuna veriler openaddressing yöntemi ile yerleştirilmiştir.
Çakışma problemini engellemek için double hashing yöntemi kullanılmıştır.


Açıklama:
Program çalışır çalışmaz bulunduğu konumda 18011706.txt isimli dosyayı çalıştırır. Bu dosya içerisindeki veriler
1 indexli satırdan itibaren (0. index başlık satırıdır) verileri okuyarak hashTable isimli structlardan oluşan diziye doldurur.
Bu dosyada satırlar;
	key kelime bulunduguDosya1 bulunduguDosya2 ...
şeklinde düzenlenmiştir. Tekrar kaydedileceği zaman yine aynı düzende kayıt edilecektir.


***MENÜ KULLANIMI***
	1)İnput eklemek için kullanılır. dosya adını dosyaadi.txt şeklinde yazınız.
	2)Kelime aramak için kullanılır. İnputlar eklendikten sonra sadece kelime adını yazarak arama yapınız
	3)LoadFactor'ü yazdırmak için kullanılır. Seçimi yapmanız yeterlidir.
	4)Tüm hashTable değerlerini ekrana yazdırmak için kullanılır.
	5)Elde bulunan hashTable dizisindeki tüm değerleri 18011706.txt isimde ve exe dosyasıyla aynı lokasyonda olacak şekilde dosyaya yazar
	6)18011706.txt dosyasının içindeki verileri ekrana yazdırmak için kullanılır.
	0)Çıkış yapmak için

Daha detalı bilgilere ulaşabilmek için Rapor.pdf dosyasını inceleyebilirsiniz.
Soru sormak için sosyal medya hesaplarıma @burakbozb1 kullanıcı adı ile ulaşabilirsiniz.
