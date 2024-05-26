import 'package:flutter/material.dart';

import 'pages/home.dart';
import 'pages/in-memory.dart';

void main() {
  runApp(const ExampleApp());
}

class ExampleApp extends StatelessWidget {
  const ExampleApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'PDFium Example',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      initialRoute: '/home',
      routes: {
        '/home': (context) => const HomePage(),
        '/in-memory': (context) => const InMemoryPage(),
        // '/pdfium-scaling': (context) => const PDFiumScalingPage(),
        // '/pdfium-thumbnails': (context) => const PDFiumThumbnails(),
        // '/pdfium-outline': (context) => const PDFiumOutlineStructure(),
        // '/search-pdf': (context) => const SearchPDF(),
        // '/pdf-metadata': (context) => const PDFMetaData(),
      },
    );
  }
}
