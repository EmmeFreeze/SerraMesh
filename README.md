# SerraMesh
 
Tutti gli esp32 o esp8266 sono connessi tra loro e scambiano messaggio in formato JSON

Tutti i dispositivi hanno la capacità di connettersi anche ad una rete wifi, ma lo effettua soltanto chi riceve il segnale migliore. -> si collegano prima alla MESH poi scansionano wifi e mandano in broadcast i risultati della scansione. 

Il nodo che si accorge di essere il più vicino alla sorgente del segnale wifi comunica agli altri di essere il "bridge" con la LAN (gli altri nodi parlano soltanto con lui)

 il nodo connesso alla LAN comunica attraverso mqtt/rest/websocket/Blynk ad un applicazione esterna per inviare dati e ricevere configurazioni. Su di esso sarà possibile comunque inserire sensori (?)

App esterna mostra statistiche riepilogative, permette di configurare un dispositivo connesso alla MESH in diverse modalità. 

I nodi della MESH utilizzano sensori ed attuatori per automatizzare la coltivazione. La possibilità di inserire sensori/attuatori è configurabile. Tramite messaggi JSON il nodo annuncia cosa è capace di fare (devices connessi) e da interfaccia si configurano i parametri.
(Capire se si può determinare la presenza di un output/input collegati)

Broadcast:

WifiAnnounce: {"msgType": "WifiAnnounce", "ssriWIFI":10}
Quando ogni dispositivo ha ricevuto un broadcast WifiAnnounce da ogni dispositivo connesso alla mesh, si determina qual'è il valore maggiore e il migliore invia un segnale per definirsi come master:

BridgeMasterAnnounce {"msgType: 
"BridgeMasterAnnounce", "master: "nomenodo"}

Tutti gli altri devices rispondono al master con un messaggio contenente le capacità che essi hanno.
(Input/output, device model).

La determinazione degli input disponibili è automatica. Si tenta l'uso di ogni sensore sui PIN predefiniti e se si ottiene una risposta si registra il componente. 

L'interfaccia permette la configurazione dei nodi attraverso msg JSON diretti al singolo nodo. 
Un nodo può controllare fino a 4 vasi (irrigazione separata  per ogni vaso ?)

Aggiungere OTA UPDATE: gateway fa broadcast a tutti i nodi. poi aggiorna se stessa. Firmware gateway (bridge) e nodi deve essere uguale



 https://www.hackster.io/davidefa/esp32-wireless-mesh-made-easy-with-painlessmesh-part-2-1cfc1d
https://www.hackster.io/davidefa/esp32-wireless-mesh-made-easy-with-painlessmesh-part-3-982af1
