import 'package:fluorflow/annotations.dart';
import 'package:fluorflow/fluorflow.dart';
import 'package:flutter/material.dart';
import 'package:flutter_pdfium/widgets.dart';

import 'bookmarks_viewmodel.dart';

@Routable(
  routeBuilder: RouteBuilder.platform,
)
final class BookmarksView extends FluorFlowView<BookmarksViewModel> {
  const BookmarksView({super.key});

  @override
  Widget builder(
          BuildContext context, BookmarksViewModel viewModel, Widget? child) =>
      Scaffold(
        appBar: AppBar(
          title: const Text('Bookmarks Example'),
        ),
        body: Column(
          children: [
            const Text('Show the bookmarks (document outline) of a PDF.'),
            const SizedBox(height: 16),
            const SizedBox(height: 8),
            const Divider(),
            const SizedBox(height: 8),
            if (viewModel.data != null)
              Expanded(
                child: Row(
                  children: [
                    Expanded(
                      child: SingleChildScrollView(
                        child: Column(
                          children: [
                            for (final bookmark in viewModel.data!.bookmarks)
                              ListTile(
                                title: Text(
                                    '${List.filled(bookmark.depth, '-').join()}${bookmark.title}'),
                                subtitle: Text(
                                    'Page ${bookmark.pageIndex + 1} (@ ${bookmark.depth} level)'),
                                onTap: () => viewModel.scrollTo(bookmark),
                              ),
                          ],
                        ),
                      ),
                    ),
                    Expanded(
                      child: SingleChildScrollView(
                        controller: viewModel.pdfScrollController,
                        padding: const EdgeInsets.only(
                            left: 16, right: 16, bottom: 32),
                        child: Column(
                          children: viewModel.data!
                              .map((page) => PageRenderer(page))
                              .toList(),
                        ),
                      ),
                    ),
                  ],
                ),
              )
          ],
        ),
      );

  @override
  BookmarksViewModel viewModelBuilder(BuildContext context) =>
      BookmarksViewModel();
}
