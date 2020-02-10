open Webapi.Dom;

let marketplaceUrl = "https://marketplace.visualstudio.com/items?itemName=iagolaguna.vscodefy"

let createGhostElement = () => document|>Document.createElement("div")

let cleanText = text => Js.String.(
  text|>replace("installs", "downloads")
)

let getInnerText = element => Belt.Option.(
  element
    ->map(el => Element.innerText(el))
    ->getWithDefault("")
)

let getDownloadsAmount = response => {

  let ghostElement = createGhostElement()
  
  Element.setInnerHTML(ghostElement, response##data)

  let text = ghostElement
    |>Element.querySelector(".installs-text")
    |>getInnerText    
    |>cleanText

  Js.log(text)

  Js.Promise.resolve(text)
}

let requestData = () => Js.Promise.(
  Axios.get(marketplaceUrl)
    |>then_(getDownloadsAmount)
)
