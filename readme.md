Запуск программы. 
1. Склонировать в папку third-party/Catch2/ https://github.com/catchorg/Catch2
2. Перейти в папку third-party/Catch2/
3. Выполнить cmake -Bbuild -H. -DBUILD_TESTING=OFF
4. Выполнить sudo cake --build build/ --target install
5. Создать в папке HW1 подпапку tmp и перейти в нее
6. Выполнить cmake ..
7. Выполнить make
8. Перейти в папку HW1/bin
9. Запустить с помощью ./ необходимый исполняемый файл
10. Для запуска теста с расширением .py выполнить ./<filename>.py из папки, где лежит файл
