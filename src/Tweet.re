open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let container = Style.[padding(10), flexDirection(`Row)];

  let ppContainer =
    Style.[borderRight(~width=3, ~color=Colors.green), borderRadius(16.0)];

  let contentContainer =
    Style.[
      border(~width=4, ~color=Colors.black),
      borderRadius(16.0),
      overflow(`Hidden),
    ];

  let text =
    Style.[
      color(Colors.black),
      fontFamily("Roboto-Black.ttf"),
      fontSize(18),
    ];
};

let component = React.component("Tweet");

let make = (~id, ()) =>
  component(hooks => {
    (
      hooks,
      <View style=Styles.container>
        <Text style=Styles.text text=id />
        <View style=Styles.ppContainer>
          <Text style=Styles.text text="PP" />
        </View>
        <View style=Styles.contentContainer>
          <Text style=Styles.text text="Content" />
        </View>
      </View>,
    )
  });

let createElement = (~children as _, ~id, ()) => make(~id, ());