from selenium import webdriver
from selenium.webdriver.firefox.options import Options as FirefoxOptions
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import logging as log
import os, time
path_to_firefox_binary = "/snap/firefox/current/usr/lib/firefox/firefox"

firefox_options = FirefoxOptions()
firefox_options.binary_location = path_to_firefox_binary

driver = webdriver.Firefox(options=firefox_options)

driver.get("https://ccp.caf.ufv.br/tccs/2023-1/")
log.info(driver.title)



download_folder_name = "poc_files"
os.makedirs(download_folder_name,exist_ok=True)
dir_path = os.path.abspath(download_folder_name)
"""  Auxiliado por ia 
    Preferencias feitaas inteiramente por ia
    """

firefox_options.set_preference("browser.download.folderList", 2) # Use custom directory
firefox_options.set_preference("browser.download.dir", dir_path) # Set the custom directory

# The rest of your preferences are fine as they were:
firefox_options.set_preference("browser.download.useDownloadDir", True)
firefox_options.set_preference("browser.download.view.columns", "MIMEType,fileName,progress,status,timeRemaining,transferRate")
firefox_options.set_preference("pdfjs.disabled", True)
firefox_options.set_preference("browser.helperApps.neverAsk.saveToDisk", "application/pdf,application/octet-stream,application/zip,text/csv")


all_links_for_download = driver.find_elements(By.PARTIAL_LINK_TEXT,"versão eletrônica")
if all_links_for_download:
    log.info(f"There is {len(all_links_for_download)} papers at this year")

    for i, link in enumerate(all_links_for_download):
        link_href = link.get_attribute('href')
        log.info(f"Link {-i + 1}: {link_href}")

        if link_href and link_href.endswith(".pdf"):
            try:
                link.click()
                log.info(f"Downloading {link_href}")
                
            except Exception as e:
                log.info(f"Failed to download {link_href}: {e}")
        else:
            log.info(f"Link {link_href} its not a pdf or whithout href")
else:
    log.info("No link 'versao eletronica' found")