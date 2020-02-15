open Webapi.Dom

let marketplaceUrl = "https://marketplace.visualstudio.com/items?itemName=iagolaguna.vscodefy"

let createGhostElement = () => document|>Document.createElement("div")

let cleanText = Js.String.replace("installs", "downloads")

let getInnerText = element => Belt.Option.(
  element
    ->map(el => Element.innerText(el))
    ->getWithDefault("")
)

let getDownloadsAmount = response => {

  let ghostElement = createGhostElement()
  
  Element.setInnerHTML(ghostElement, response##data)

  ghostElement
    |>Element.querySelector(".installs-text")
    |>getInnerText    
    |>cleanText
    |>Js.Promise.resolve
}

let requestData = () => Js.Promise.(
  Axios.get(marketplaceUrl)
    |>then_(getDownloadsAmount)
)
