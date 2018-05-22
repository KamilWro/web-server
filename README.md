# web-server
Implementacja prostego serwera WWW, obsługujący żądania protokołu komunikacyjnego HTTP. Wyświeta strony z zadanego katalogu</br>
Realizowane zadania:
- [x] obsługa żądań GET (pole Host i pole Connection)
- [x] odsyła informacje: kod odpowiedzi, pole Content-Type i pole Content-Length.
- [x] zwraca następujące kody odpowiedzi: 200 (OK), 301(Moved Permanently), 403 (Forbidden), 404 (Not Found), 501 ( Not Implemented)
- [x] obsługa plików: txt, html, css, jpg, jpeg, png i pdf. Pozostałe pliki mają typ application/octet-stream
- [x] po nawiązaniu połączenia serwer utrzymuje połączenie z nieaktywnym klientem przez 1s (zamykane w przypadku odebrania Connection: close)
- [ ] obsługa wiele klientów jednocześnie

### Przed uruchomieniem: 
Skonfiguruj lokalne rozwiązywanie nazw DNS dopisując do pliku /etc/hosts następujące wpisy: </br>
`127.10.10.1 domena1.sieci.edu` </br>
`127.10.10.2 domena2.sieci.edu` </br>
Od tej pory odwołania do powyższych domen będą kierowane do lokalnego komputera. </br>
 </br>
### Uruchomienie:
`./server port dictionary` </br>
`port` - numer portu, na którym serwer będzie oczekiwać na przychodzące połączenia (np. `8888`) </br>
`directory` - katalog zawierającym strony WWW (np. `../strony-www/`) </br>
 </br>
następnie w przeglądarce wpisać adres: `domena1.sieci.edu:8888/` </br>
