import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/material.dart';

import 'app.locator.dart';
import 'app.router.dart';

void main() async {
  await setupLocator();
  runApp(const ExampleApp());
}

class ExampleApp extends StatelessWidget {
  const ExampleApp({super.key});

  @override
  Widget build(BuildContext context) => MaterialApp(
        title: 'PDFium Example',
        theme: ThemeData(
          colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepOrange),
          useMaterial3: true,
        ),
        initialRoute: AppRoute.homeView.path,
        onGenerateRoute: onGenerateRoute,
        navigatorKey: NavigationService.navigatorKey,
        navigatorObservers: [NavigationService.observer],
      );
}
