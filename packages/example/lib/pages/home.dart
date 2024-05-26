import 'package:flutter/material.dart';

class HomePage extends StatelessWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) => Scaffold(
        appBar: AppBar(
          title: const Text('Flutter PDFium Demo'),
        ),
        body: Center(
          child: SingleChildScrollView(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.start,
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                const Text(
                    'This uses PDFium to load and display a PDF document.'),
                TextButton(
                  child: const Text('Load PDF from Memory.'),
                  onPressed: () =>
                      Navigator.of(context).pushNamed('/in-memory'),
                ),
                // TextButton(
                //   child: const Text('Scale PDF Rendering.'),
                //   onPressed: () =>
                //       Navigator.of(context).pushNamed('/pdfium-scaling'),
                // ),
                // TextButton(
                //   child: const Text('PDF Thumbnails.'),
                //   onPressed: () =>
                //       Navigator.of(context).pushNamed('/pdfium-thumbnails'),
                // ),
                // TextButton(
                //   child: const Text('PDF Structure / outline.'),
                //   onPressed: () =>
                //       Navigator.of(context).pushNamed('/pdfium-outline'),
                // ),
                // TextButton(
                //   child: const Text('Search through PDF.'),
                //   onPressed: () => Navigator.of(context).pushNamed('/search-pdf'),
                // ),
                // TextButton(
                //   child: const Text('Explore available metadata.'),
                //   onPressed: () =>
                //       Navigator.of(context).pushNamed('/pdf-metadata'),
                // ),
              ],
            ),
          ),
        ),
      );
}
