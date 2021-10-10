import matplotlib.pyplot as plt
import numpy as np


print("Oto prosta wizualizacja funkcji ax^2+bx+c")
wyroznik1 = float(input("Wspolczynnik 1: "))
wyroznik2 = float(input("Wspolczynnik 2: "))
wyroznik3 = float(input("Wspolczynnik 3: "))
opisx = input("Wprowadź opis dla osi x:")
opisy = input("Wprowadź opis dla osi y: ")
tytul = input("Wprowadź tytul wykresu: ")
#GranicaDolna = input("Wprowadź granice dolna osi OX wykresu: ")
#GranicaGorna = input("Wprowadź granice gorna osi OX wykresu: ")
wartoscx = np.linspace(-4, 4, 5000)
wartoscy = np.array([wyroznik1*(x**2)+wyroznik2*(x)+ wyroznik3 for x in wartoscx])

fix, a = plt.subplots(figsize=(5,5))

a.plot(wartoscx, wartoscy)
plt.xlabel(opisx)
plt.ylabel(opisy)
plt.title(tytul)


plt.show()


#Z czystej ciekawości, jak możnaby było podstawić zmienne w matplotlib.pyplot.linespace()[wyrzuca błąd przy każdej próbie wstawienia zmiennej]?
#Oczywiście możemy narysować dla ogromnego przedziału zamiast <-4,4> a potem przesuwać za pomocą kontrolek ale jest to niezbyt praktyczne, zwłaszcza kiedy interesuje nas tylko określony, mały wycinek funkcji
