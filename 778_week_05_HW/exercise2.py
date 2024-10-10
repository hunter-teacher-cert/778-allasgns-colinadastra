import random, json, imutils, cv2, ssl
from urllib.error import HTTPError
from urllib.request import urlopen

# Necessary step to get my computer to blindly trust NASA's certificates...
ssl._create_default_https_context = ssl._create_unverified_context

# Ask the user for the search term
term = input(">> Enter a search term: ")
base1 = f"https://images-api.nasa.gov/search?q={term}&media_type=image"

# Access the search results and print the search URL
response = urlopen(base1)
object = json.loads(response.read())
print(f">> Searched at {object['collection']['href']}")

# If an image is available, print its information and display it
try:
    # Choose a random image from the results
    items = object['collection']['items']
    item = items[random.randint(0,len(items))]

    # Access and print information about the image
    title = item['data'][0]['title']
    date = item['data'][0]['date_created']
    id = item['data'][0]['nasa_id']
    print(f">> Found this image at random:")
    print(f"Title: \t\t{title}")
    print(f"Created: \t{date}")
    print(f"NASA Id: \t{id}")

    # Access the image itself
    base2 = f"https://images-api.nasa.gov/asset/{id}"
    response = urlopen(base2)
    object = json.loads(response.read())
    img = imutils.url_to_image(object['collection']['items'][1]['href'],)

    # Display the image itself
    cv2.imshow(title + ' ' + date, img)
    cv2.waitKey(0)
# If no images are available, inform the user
except (HTTPError, IndexError):
    print(">> No images found")
