import requests
import shutil

response = requests.get("http://localhost:8080/slownik.txt", auth=("karaf","karaf"), stream=True)
with open("resp.txt", 'wb') as out_file:
    shutil.copyfileobj(response.raw, out_file)
del response
