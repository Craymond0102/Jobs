from mechanize import Browser, Control
from selenium import webdriver as driver
from time import sleep
from threading import Timer
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
from tdameritrade import TDClient
import tdameritrade.auth as au



#----------------------------------------------------------
#----------------------------------------------------------
#----------------------------------------------------------
#   This is the refresh_Token. It gets send to the 
#   TD Ameritrade servers and gets the access token
#----------------------------------------------------------
REFRESH_TOKEN = 'CkbDw/fmCo/4UAD+FRf2v1pGet3OsG9eRMvJLkdfUD4HlFZkuf7hl1zOmMQ91SiDruIMQgCxBLA3D6hODogqZsU1se+L98DP8We0i+D19IS5GKOKOCiP32hom7fpi4AZAsA25lEjFls/X89wdjlhMsyoPr7EdI9iAnIakl8Xem3BKhNQEh/WuciKc8fDEaj3qpSVeFGXlnqQDg2IiSorYikoau25CXxqiDdntZ0HNVfHyKIzRE98KZdJmNwlUF3fF0pH9RoZM8PYhm4r9u3DUv25l6GYwwr2HCtNnZUUJU3NuMCZQraBPRdUYAMRG35WdaLztLR3ieC5tvMBa17s1rAgGP2pPWwvNDba7gcInZOfFWyGFOZS4+2oM167rVbkudI9gEReRfEVKHjpCcPrjJfv8JkGFcfk+WHdihTzxMdcm8SmUiIkEeXYHr4100MQuG4LYrgoVi/JHHvlEisTc06B17L6mv+sKdFdPNf1Xb2T6NFQDJmnOmfW+dOTQ70qFkPJz009YptiPZv/VfWT7NwOIpMjLd5S8FpbFTmDsmrwXtsqMus7ZIfupCtc0tEjx6SsJpeOFabCMsyleKli7pyZEnzmjOQaXLGGruR9wr0/tQ5Si+Jv9a6j7NCj08Zt31UOSDLHXG4tmS5fNNzI7bbJr8L0iv3YO/pEVfdjZGsu18sLLi7KjUDM7uVpBo6jVka42h9IUg+mWHcN3OvtppNwtiUbK+Qm1z8iXkXpnMOsVRn005RUaS8qc5jTIC4BNFkpoHv+wwiJyXEdEtCkbnKElshPJHCGbLpcvClcKtsf4dRclhs3V7lNyZHGkL/xFlrXQRGuYuDnUeztQ7KeFDBX4O2fqUkxDSQZkSqRLkXzgPX8UI1wKhUxUp/a+ADiT489soLViwA=212FD3x19z9sWBHDJACbC00B75E'
#----------------------------------------------------------
#   This key will last for 90 days, Today is 3/6/19
#           Roughly renew around 6/1/19
#----------------------------------------------------------



#----------------------------------------------------------
#   logs into TD Ameritrade and then
#   returns the url of the logeddin
#   account
#----------------------------------------------------------
def login():
    br = Browser()

    br.set_handle_robots( False )
    br.addheaders = [('User-agent', 'Chrome')]
    br.open("https://auth.tdameritrade.com")

    br.select_form( id = "authform" )
    br.form[ 'su_username' ] = "rilolong"
    br.form[ 'su_password' ] = "Rupert111"
    
    no_url = br.submit()
    url = no_url.geturl()
    return url



#html = login()
#print(html)
#access_Trade(html)
#print(login())
#access_Trade


#----------------------------------------------------------
#   Gets to the main dashboard, then executes a trade
#   
#----------------------------------------------------------
def access_Trade(url):

    driver = webdriver.Chrome(executable_path="/Users/charlesraymond/Documents/chromedriver")
    driver.get(url)
    sleep(3) 

    driver.find_element_by_link_text("Trade").click()
    driver.find_element_by_id ("symbol").send_keys("UGAZ")#.send_keys(Keys.ENTER)
    driver.find_element_by_link_text("Stocks & ETFs").click()
    sleep(3)
    select = Select(driver.find_element_by_id('action'))
    select.select_by_value('SELL')
    select = Select(driver.find_element_by_id('orderType'))
    select.select_by_value('MARKET')

    #print(driver.page_source)

def timeout():
    print("Alarm!")

timer = Timer(1500.0, timeout)
timer.start()

response = au.refresh_token(REFRESH_TOKEN, 'CHARLIEQ')
print(response)

c = TDClient(response['access_token'])
c.accounts()

#access_Trade(html)


again = True;


while again:

    #print("current Price")
    if timer.is_alive() == False:
        print("STOPPED")
        response = au.refresh_token(REFRESH_TOKEN, 'CHARLIEQ')
        c = TDClient(response['access_token'])
        c.accounts()
        timer = Timer(1500.0, timeout)
        timer.start()

    quote = c.quote('ugaz')
    current_price = quote['UGAZ']['lastPrice']
    print("Current Price: " + str(current_price))
    sleep(1.5)


###if current_price >= our price
###sell
###if current_price <= our price
###buy
### fill in with algorithm





